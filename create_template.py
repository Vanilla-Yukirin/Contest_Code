# 将template.cpp的内容生成.vscode/cp.code-snippets
import json
from pathlib import Path

with open("template.cpp", "r", encoding="utf-8") as f:
    lines = [line.rstrip("\n") for line in f]

snippet = {
    "My CP Template": {
        "prefix": "cp",
        "body": lines,
        "description": "竞赛代码模板"
    }
}

output_path = Path(".vscode") / "cp.code-snippets"
output_path.parent.mkdir(parents=True, exist_ok=True)

with open(output_path, "w", encoding="utf-8") as f:
    json.dump(snippet, f, ensure_ascii=False, indent=2)
    f.write("\n")

print(f"Saved snippet to: {output_path}")

