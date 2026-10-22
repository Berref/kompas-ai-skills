# Шпаргалка по API КОМПАС-3D (Python)

## CLSID / ProgID

| Назначение | Идентификатор |
|---|---|
| Приложение (API5) | `Kompas.Application.5` |
| Приложение (API7) | `Kompas.Application.7` |
| Константы 2D | `{75C9F5D0-B5B8-4526-8681-9903C567D2ED}` |
| Константы 3D | `{2CAF168C-7961-4B90-9DA2-701419BEEFE3}` |
| Интерфейсы API5 (`KompasObject`) | `{0422828C-F174-495E-AC5D-D31014DBBE87}` |
| Интерфейсы API7 (`IApplication`) | `{69AC2981-37C0-4379-84FD-5DD2F3C0A520}` |

## Базовая цепочка для 2D

```text
Application
  └─ ActiveDocument
       └─ IKompasDocument2D
            └─ ViewsAndLayersManager
                 └─ Views
                      └─ ActiveView
                           └─ IDrawingContainer
                                └─ LineSegments / Arcs / Circles / ...
---

### 📄 `kompas-sources.md`
```markdown
# Источники для поиска решений по API КОМПАС-3D

## Официальные ресурсы АСКОН

| Ресурс | URL | Назначение |
|---|---|---|
| Учебный форум АСКОН | `https://sdo.ascon.ru/mod/forum/` | Типовые ошибки, примеры, обсуждения |
| Форум «Технологии АСКОН» (архив) | `https://sd7.ascon.ru/` | Исторические обсуждения API |
| Техподдержка по API | `https://sd.ascon.ru/` | Запрос SDK и справочных материалов |
| Документация SDK | `https://help.ascon.ru/KOMPAS_SDK/` | Справочник по интерфейсам и примерам |

## GitHub-репозитории

- `Mikarisar/KOMPAS_tools` — обёртка для автоматизации 2D-построений.
- `Mukovenkov-Roman-Sergeyevich/KompasPack` — упаковка проектов с исправлением путей.
- `lis3809/macros_for_Kompas-3D` — макросы, включая сохранение чертежей из 3D.
- `Lolevtexa/visio_to_kompas3d_convertor` — конвертер Visio → КОМПАС.
- `nikolai-in/Geodesy` — пример автоматизации учебного задания.
- `frei480/-22-SDK` — справочные материалы по SDK v22.

## Поисковые запросы

- `kompas-3d python`
- `kompas api python`
- `Kompas.Application.7`
- `IDrawingContainer`
- `LineSegments`
