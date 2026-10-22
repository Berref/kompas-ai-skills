# kompas-ai-skills

Набор переиспользуемых навыков (skills) для AI-ассистентов (Koda, Claude Code, Codex и других), специализирующихся на автоматизации КОМПАС-3D через Python API (COM/pywin32).

## 📦 Структура репозитория

- `skills/kompas-python-api/` — основной навык для работы с 2D/3D документами, свойствами и экспортом.
  - `SKILL.md` — основное описание, жёсткие правила и контекст для ИИ.
  - `references/` — шпаргалки по API, проверенные источники и руководство по устранению типовых ошибок.
  - `examples/` — готовые, проверенные примеры скриптов, которые ИИ может использовать как эталонный шаблон.

## 🚀 Установка

### Koda (локально, для проекта)
```bash
git clone https://github.com/Berref/kompas-ai-skills.git
cp -r kompas-ai-skills/skills/kompas-python-api <ваш-проект>/.koda/skills/

### Claude Code (локально, для проекта)
```bash
# Глобально для пользователя
git clone https://github.com/Berref/kompas-ai-skills.git
cp -r kompas-ai-skills/skills/kompas-python-api ~/.claude/skills/

# Или локально для конкретного проекта
cp -r kompas-ai-skills/skills/kompas-python-api <ваш-проект>/.claude/skills/
