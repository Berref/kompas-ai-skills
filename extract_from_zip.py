import zipfile
import re
from pathlib import Path

# ==========================================
# НАСТРОЙКИ
# ==========================================
ZIP_PATH = Path(r"C:\Program Files\ASCON\KOMPAS-3D v23\SDK\Help\KOMPAS_SDK_ru-RU.zip")
OUTPUT_FILE = Path("skills/kompas-python-api/references/kompas-api-core-reference.md")

def clean_text(text: str) -> str:
    """Очищает текст от HTML-мусора, переносов строк и лишних пробелов."""
    text = re.sub(r'<[^>]+>', '', text)
    text = text.replace('&nbsp;', ' ').replace('&quot;', '"')
    return ' '.join(text.split()).strip()

def categorize_item(name: str, desc: str) -> str:
    """Распределяет элементы по логическим категориям для ИИ."""
    combined = (name + " " + desc).lower()
    
    if any(k in combined for k in ["kompasobject", "iapplication", "application"]):
        return "1. Приложение и KompasObject"
    if any(k in combined for k in ["document2d", "document3d", "графический документ", "текстовый документ", "спецификация"]):
        return "2. Документы (2D/3D/Спецификации)"
    if any(k in combined for k in ["файл", "file", "path", "путь", "save", "open", "choice", "uniquefilename"]):
        return "3. Работа с файлами"
    if any(k in combined for k in ["вывод", "экран", "сообщен", "диалог", "bitmap", "slide", "message", "yesno", "error", "draw"]):
        return "4. Вывод на экран и диалоги"
    if any(k in combined for k in ["сервисн", "верси", "систем", "задач", "доступ", "help", "справк", "clearfilecache"]):
        return "5. Сервисные функции"
    if any(k in combined for k in ["лини", "отрезк", "дуг", "окружност", "крив", "контур", "line", "arc", "circle", "curve", "contour", "spline"]):
        return "6. 2D Геометрия"
    if any(k in combined for k in ["модель", "тело", "грань", "ребро", "вершин", "model", "body", "face", "edge", "vertex"]):
        return "7. 3D Топология"
    if any(k in combined for k in ["операци", "выдавливан", "вырез", "эскиз", "скруглен", "фаск", "отверст", "резьб", "operation", "extrusion", "cut", "sketch", "fillet", "chamfer"]):
        return "8. 3D Операции"
    if any(k in combined for k in ["сборк", "детал", "компонент", "assembly", "part", "component"]):
        return "9. Сборки и компоненты"
    if any(k in combined for k in ["размер", "dimension"]):
        return "10. Размеры"
    if any(k in combined for k in ["текст", "надпис", "обозначен", "штриховк", "text", "note", "leader", "hatch"]):
        return "11. Аннотации и текст"
    if any(k in combined for k in ["свойств", "атрибут", "параметр", "переменн", "материал", "штамп", "property", "attribute", "parameter", "material", "stamp"]):
        return "12. Свойства и атрибуты"
    if any(k in combined for k in ["вид", "слой", "стиль", "цвет", "view", "layer", "style", "color"]):
        return "13. Виды, слои и стили"
    
    return "14. Прочие методы и интерфейсы"

def main():
    if not ZIP_PATH.exists():
        print("ОШИБКА: Архив не найден:", ZIP_PATH)
        return

    print("Чтение архива:", ZIP_PATH.name)
    
    categorized_data = {}
    found_count = 0
    processed_files = 0

    # Слова для игнорирования (навигация, примеры, общие статьи)
    IGNORE_TITLES = {'Scroll', 'Содержание', 'Указатель', 'Поиск', 'Поделиться', 'Сайт АСКОН', 'Видео', 'Статьи', 'Форум', 'Поддержка', 'ВКонтакте'}

    try:
        with zipfile.ZipFile(ZIP_PATH, 'r') as zip_ref:
            html_files = [f for f in zip_ref.namelist() if f.lower().endswith('.html')]
            print(f"Найдено HTML-файлов: {len(html_files)}")
            print("Начинаем извлечение...")

            for file_path in html_files:
                processed_files += 1
                try:
                    content = zip_ref.read(file_path).decode('utf-8', errors='ignore')
                    
                    # 1. Извлекаем заголовок страницы
                    title_match = re.search(r'<title>(.*?)</title>', content, re.IGNORECASE)
                    if not title_match:
                        continue
                    
                    raw_title = clean_text(title_match.group(1))
                    
                    # Игнорируем мусорные заголовки
                    if raw_title in IGNORE_TITLES or len(raw_title) < 3:
                        continue
                    if any(ignore in raw_title for ignore in ['Пример использования', 'Пример регистрации', 'Руководство пользователя']):
                        continue

                    # 2. Извлекаем описание из meta description (самый чистый источник!)
                    desc_match = re.search(r'<meta name="description" content="(.*?)"', content, re.IGNORECASE)
                    if desc_match:
                        description = clean_text(desc_match.group(1))
                    else:
                        description = "Описание отсутствует в meta-теге."

                    # Если описание слишком короткое или бессмысленное, пропускаем
                    if len(description) < 15 or description.startswith("Enter your company name"):
                        continue

                    # 3. Категоризация
                    category = categorize_item(raw_title, description)
                    if category not in categorized_data:
                        categorized_data[category] = {}
                    
                    # 4. Добавляем, избегая дубликатов по имени
                    if raw_title not in categorized_data[category]:
                        categorized_data[category][raw_title] = description
                        found_count += 1

                except Exception:
                    continue

    except zipfile.BadZipFile:
        print("ОШИБКА: файл не является корректным ZIP-архивом.")
        return

    # ==========================================
    # ГЕНЕРАЦИЯ ИТОГОВОГО ФАЙЛА
    # ==========================================
    print("Формирование итогового файла...")
    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)
    
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as out:
        out.write("# 📚 Справочник API КОМПАС-3D (для AI)\n\n")
        out.write("> Автоматически извлечено из `KOMPAS_SDK_ru-RU.zip`.\n")
        out.write("> Содержит названия методов/свойств и их краткий синтаксис из meta-описаний.\n\n")
        out.write("---\n\n")

        for category, items in sorted(categorized_data.items()):
            out.write(f"## {category}\n\n")
            out.write("| Название | Описание и синтаксис |\n")
            out.write("|---|---|\n")
            
            for name in sorted(items.keys()):
                desc = items[name]
                out.write(f"| **`{name}`** | {desc} |\n")
            
            out.write("\n---\n\n")

    print("✅ ГОТОВО!")
    print("Файл сохранен:", OUTPUT_FILE.resolve())
    print("Обработано файлов:", processed_files)
    print("Найдено полезных элементов:", found_count)

if __name__ == "__main__":
    main()
