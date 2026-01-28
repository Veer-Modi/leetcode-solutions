## 🤖 Automated LeetCode Sync

This repository uses **GitHub Actions + Playwright** to automatically:

- Log in to LeetCode securely
- Fetch solved problem statistics
- Sync progress into this repository
- Auto-commit and push changes

### 🔁 How it works

- A GitHub Action runs daily (or manually)
- Playwright logs in like a real browser
- LeetCode data is fetched via GraphQL
- Updates are committed automatically

### 📊 Synced Data

- `leetcode/problems/` → solutions
- `leetcode/stats/summary.json` → solved counts by difficulty

### 🔐 Security

- No cookies stored
- No session tokens
- Uses GitHub Secrets for credentials

### ▶ Manual Run

Go to **GitHub → Actions → Sync LeetCode Solutions → Run workflow**

---

⚠️ This automation is unofficial and respects rate limits.
