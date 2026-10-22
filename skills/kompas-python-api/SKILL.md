---
name: kompas-python-api
description: Автоматизация КОМПАС-3D через Python API (COM/pywin32) — подключение, 2D/3D-документы, построение геометрии, свойства, экспорт, обработка ошибок, поиск решений на форуме АСКОН и в GitHub.
tags: [kompas, kompas-3d, python, cad, automation, pywin32, com, api, ascon-forum, github]
when_to_use: >
  Используй этот навык, когда пользователь просит написать, исправить или объяснить
  Python-скрипт для КОМПАС-3D: построение детали или чертежа, заполнение штампа,
  извлечение свойств, пакетный экспорт, работа с API5/API7, обход ошибок COM,
  а также когда нужно найти готовое решение или пример кода на форуме АСКОН
  или в открытых GitHub-репозиториях.
license: MIT
metadata:
  author: Berref
  version: 1.0.0
---

# Автоматизация КОМПАС-3D через Python

## 0. Жёсткие правила (не нарушать)

1. **Только Windows.** API КОМПАС-3D работает через COM. Скрипты не будут работать на Linux/macOS без Windows-окружения.
2. **Требуется установленный КОМПАС-3D.** Библиотеки `pywin32` сами по себе не содержат API Компаса — они лишь подключаются к запущенному приложению.
3. **`pythoncom.CoInitialize()` обязателен** в начале скрипта и `pythoncom.CoUninitialize()` в конце, если скрипт запускается из фонового потока или сервиса.
4. **Не выдумывай методы и свойства.** Если не уверен в имени интерфейса или метода — сначала поищи в источниках из раздела 8–10 или предложи пользователю уточнить версию Компаса.
5. **Не используй относительные пути в скриптах навыка**, если добавляешь вспомогательные файлы: указывай абсолютные пути или пути относительно корня проекта явно.

## 1. Подключение к API (базовый шаблон)

Минимальный проверенный шаблон подключения через `pywin32` и `gencache`:

```python
import pythoncom
from win32com.client import Dispatch, gencache

def connect_kompas():
    pythoncom.CoInitialize()

    # Константы API Компас (2D)
    const = gencache.EnsureModule(
        "{75C9F5D0-B5B8-4526-8681-9903C567D2ED}", 0, 1, 0
    ).constants

    # Константы API Компас (3D)
    const_3d = gencache.EnsureModule(
        "{2CAF168C-7961-4B90-9DA2-701419BEEFE3}", 0, 1, 0
    ).constants

    # Интерфейсы API5 (KompasObject)
    KAPI = gencache.EnsureModule(
        "{0422828C-F174-495E-AC5D-D31014DBBE87}", 0, 1, 0
    )
    kompas_object = KAPI.KompasObject(
        Dispatch("Kompas.Application.5")._oleobj_.QueryInterface(
            KAPI.KompasObject.CLSID, pythoncom.IID_IDispatch
        )
    )

    # Интерфейсы API7 (IApplication)
    KAPI7 = gencache.EnsureModule(
        "{69AC2981-37C0-4379-84FD-5DD2F3C0A520}", 0, 1, 0
    )
    application = KAPI7.IApplication(
        Dispatch("Kompas.Application.7")._oleobj_.QueryInterface(
            KAPI7.IApplication.CLSID, pythoncom.IID_IDispatch
        )
    )
    application.Visible = True

    return {
        "pythoncom": pythoncom,
        "const": const,
        "const_3d": const_3d,
        "KAPI": KAPI,
        "KAPI7": KAPI7,
        "kompas_object": kompas_object,
        "application": application,
    }
