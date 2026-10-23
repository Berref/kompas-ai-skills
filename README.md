# kompas-ai-skills

Набор переиспользуемых навыков (skills) для AI-ассистентов (Koda, Claude Code, Codex и других), специализирующихся на автоматизации CAD-систем через Python API.

Сейчас поддерживаются:

- **КОМПАС-3D** — через COM (pywin32).
- **Autodesk Revit** — через pyRevit / Revit API (.NET, IronPython).

## 📦 Структура репозитория

```
kompas-ai-skills/
└── skills/
    ├── kompas-python-api/          # КОМПАС-3D (COM / pywin32)
    │   ├── SKILL.md
    │   ├── references/
    │   └── examples/
    └── revit-python-api/           # Autodesk Revit (pyRevit / .NET)
        ├── SKILL.md
        ├── references/
        └── examples/
```

Каждый навык устроен одинаково:

- `SKILL.md` — основное описание, жёсткие правила и контекст для ИИ.
- `references/` — шпаргалки по API, проверенные источники и руководство по устранению типовых ошибок.
- `examples/` — готовые, проверенные примеры скриптов, которые ИИ может использовать как эталонный шаблон.

## 🧩 Что внутри навыков

### `kompas-python-api`

Автоматизация КОМПАС-3D через COM:

- подключение к запущенному КОМПАС или создание нового;
- работа с 2D/3D документами;
- чтение и запись свойств;
- экспорт и сохранение.

### `revit-python-api`

Автоматизация Autodesk Revit через pyRevit / Revit API:

- `FilteredElementCollector` — сбор элементов по классу и виду;
- чтение и запись параметров (`LookupParameter`, `StorageType`, `Set`);
- работа со спецификациями (`ViewSchedule`, поля сортировки, `ShowHeader`);
- теги и заметки на планах (`IndependentTag`, `TextNote`);
- экспорт в Excel через COM;
- транзакции при изменении модели.

## 🚀 Установка

### Koda (локально, для проекта)

```bash
git clone https://github.com/Berref/kompas-ai-skills.git

# Только КОМПАС
cp -r kompas-ai-skills/skills/kompas-python-api <ваш-проект>/.koda/skills/

# Только Revit
cp -r kompas-ai-skills/skills/revit-python-api <ваш-проект>/.koda/skills/

# Оба навыка
cp -r kompas-ai-skills/skills/kompas-python-api \
      kompas-ai-skills/skills/revit-python-api <ваш-проект>/.koda/skills/
```

### Claude Code (локально, для проекта)

```bash
# Глобально для пользователя — только КОМПАС
git clone https://github.com/Berref/kompas-ai-skills.git
cp -r kompas-ai-skills/skills/kompas-python-api ~/.claude/skills/

# Глобально для пользователя — только Revit
cp -r kompas-ai-skills/skills/revit-python-api ~/.claude/skills/

# Глобально для пользователя — оба навыка
cp -r kompas-ai-skills/skills/kompas-python-api \
      kompas-ai-skills/skills/revit-python-api ~/.claude/skills/

# Или локально для конкретного проекта
cp -r kompas-ai-skills/skills/kompas-python-api \
      kompas-ai-skills/skills/revit-python-api <ваш-проект>/.claude/skills/
```

### Требования

| Навык | Что нужно установить |
|-------|----------------------|
| `kompas-python-api` | Windows, КОМПАС-3D, Python, `pywin32` (`pythoncom`, `win32com.client`) |
| `revit-python-api`  | Windows, Autodesk Revit 2020+, pyRevit (IronPython 2.7) |

## 📖 Использование

После копирования в `.koda/skills/` или `~/.claude/skills/` AI-ассистент автоматически увидит навык по метаданным в `SKILL.md` (поля `name`, `description`, `keywords`) и подхватит его в контекст, когда задача касается соответствующей CAD-системы.

Примеры запросов:

- «Собери все опоры с параметром `RI_ПП_Зона` и выгрузи в Excel» — сработает `revit-python-api`.
- «Проставь позиции по полям сортировки активной спецификации» — сработает `revit-python-api`.
- «Открой чертёж КОМПАС и прочитай свойства штампа» — сработает `kompas-python-api`.

## 🛠 Расширение

Чтобы добавить новый навык:

1. Создайте папку `skills/<имя-навыка>/`.
2. Внутри — `SKILL.md` с frontmatter:
   ```yaml
   ---
   name: имя-навыка
   description: что делает и когда использовать
   keywords: [список, ключевых, слов]
   ---
   ```
3. Папки `references/` и `examples/` по аналогии с существующими.
4. Обновите этот `README.md` (списки в разделе «Что внутри» и «Установка»).

## 📄 Лицензия

См. файл `LICENSE` в корне репозитория.
