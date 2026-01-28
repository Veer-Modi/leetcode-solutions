const { chromium } = require("playwright");
const fs = require("fs");
const path = require("path");
const { execSync } = require("child_process");

(async () => {
  const browser = await chromium.launch({ headless: true });
  const context = await browser.newContext();
  const page = await context.newPage();

  console.log("➡ Opening LeetCode login page...");
  await page.goto("https://leetcode.com/accounts/login/", {
    waitUntil: "networkidle",
  });

  await page.fill('input[name="login"]', process.env.LEETCODE_USERNAME);
  await page.fill('input[name="password"]', process.env.LEETCODE_PASSWORD);
  await page.click('button[type="submit"]');

  await page.waitForTimeout(5000 + Math.random() * 4000);
  if (!page.url().includes("leetcode.com")) {
    throw new Error("❌ Login failed");
  }

  console.log("✅ Login successful");

  // ---------- FETCH SOLVED PROBLEMS ----------
  console.log("📡 Fetching solved problems...");

  const result = await page.evaluate(async () => {
    const res = await fetch("https://leetcode.com/graphql", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        query: `
          query getSolved {
            allQuestionsCount {
              difficulty
              count
            }
            matchedUser(username: "${process.env.LEETCODE_USERNAME}") {
 {
              submitStats {
                acSubmissionNum {
                  difficulty
                  count
                }
              }
            }
          }
        `,
      }),
    });
    return res.json();
  });

  const stats = result.data.matchedUser.submitStats.acSubmissionNum;

  const outputDir = path.join("leetcode", "stats");
  fs.mkdirSync(outputDir, { recursive: true });

  fs.writeFileSync(
    path.join(outputDir, "summary.json"),
    JSON.stringify(stats, null, 2),
  );

  console.log("✅ Stats saved to leetcode/stats/summary.json");

  // ---------- AUTO COMMIT ----------
  console.log("📦 Committing changes...");

  try {
    execSync("git config user.name 'leetcode-bot'");
    execSync("git config user.email 'leetcode-bot@users.noreply.github.com'");
    execSync("git add .");
    execSync("git commit -m 'chore: auto-sync leetcode progress'", {
      stdio: "ignore",
    });
    execSync("git push");
    console.log("🚀 Changes pushed to GitHub");
  } catch {
    console.log("ℹ️ No new changes to commit");
  }

  await browser.close();
})();
