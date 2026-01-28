const { chromium } = require("playwright");
const fs = require("fs");
const path = require("path");
const { execSync } = require("child_process");

(async () => {
  const browser = await chromium.launch({ headless: true });

  // More human-like browser context
  const context = await browser.newContext({
    userAgent:
      "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
  });

  const page = await context.newPage();
  page.setDefaultTimeout(60000);

  console.log("➡ Opening LeetCode login page...");

  // IMPORTANT FIX: do NOT use networkidle
  await page.goto("https://leetcode.com/accounts/login/", {
    waitUntil: "domcontentloaded",
    timeout: 60000,
  });

  // Wait for login form
  await page.waitForSelector('input[name="login"]', { timeout: 60000 });

  await page.fill('input[name="login"]', process.env.LEETCODE_USERNAME);
  await page.fill('input[name="password"]', process.env.LEETCODE_PASSWORD);

  await page.click('button[type="submit"]');

  // Human-like delay
  await page.waitForTimeout(5000 + Math.random() * 4000);

  if (!page.url().includes("leetcode.com")) {
    throw new Error("❌ Login failed");
  }

  console.log("✅ Login successful");

  // ---------- FETCH SOLVED STATS ----------
  console.log("📡 Fetching solved problems...");

  const result = await page.evaluate(async (username) => {
    const res = await fetch("https://leetcode.com/graphql", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        query: `
          query getSolved($username: String!) {
            matchedUser(username: $username) {
              submitStats {
                acSubmissionNum {
                  difficulty
                  count
                }
              }
            }
          }
        `,
        variables: { username },
      }),
    });
    return res.json();
  }, process.env.LEETCODE_USERNAME);

  const stats = result?.data?.matchedUser?.submitStats?.acSubmissionNum || [];

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
    execSync("git commit -m 'chore: auto-sync leetcode progress'");
    execSync("git push");
    console.log("🚀 Changes pushed to GitHub");
  } catch {
    console.log("ℹ️ No new changes to commit");
  }

  await browser.close();
})();
