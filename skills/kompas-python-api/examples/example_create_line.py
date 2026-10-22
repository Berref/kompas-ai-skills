"""
Пример: Работа с активным 2D-документом и отрисовка отрезка в КОМПАС-3D.
Этот файл служит эталонным шаблоном для ИИ при генерации скриптов автоматизации.
"""
import pythoncom
from win32com.client import Dispatch, gencache

def main():
    # 1. Инициализация COM (ОБЯЗАТЕЛЬНО, см. правило 3 в SKILL.md)
    pythoncom.CoInitialize()
    
    try:
        # 2. Загрузка констант и интерфейсов API 5
        KAPI = gencache.EnsureModule("{0422828C-F174-495E-AC5D-D31014DBBE87}", 0, 1, 0)
        
        # 3. Подключение к запущенному приложению КОМПАС-3D
        kompas_object = KAPI.KompasObject(
            Dispatch("Kompas.Application.5")._oleobj_.QueryInterface(
                KAPI.KompasObject.CLSID, pythoncom.IID_IDispatch
            )
        )
        kompas_object.Visible = True

        # 4. Получение активного 2D-документа (чертежа)
        document = kompas_object.ActiveDocument2D()
        if not document:
            print("Ошибка: Нет активного 2D-документа. Пожалуйста, откройте чертеж в КОМПАС-3D.")
            return

        # 5. Отрисовка отрезка
        # ksLineSeg(x1, y1, x2, y2, style)
        # style: 1 - основная линия, 3 - осевая и т.д.
        document.ksLineSeg(100, 100, 200, 200, 1)

        # 6. Обновление изображения (КРИТИЧЕСКИ ВАЖНО, см. kompas-troubleshooting.md)
        document.ksUpdateDocument()
        
        print("Отрезок успешно создан и отображен в активном документе.")

    except Exception as e:
        print(f"Ошибка при работе с КОМПАС-3D: {e}")
        
    finally:
        # 7. Очистка COM (ОБЯЗАТЕЛЬНО)
        pythoncom.CoUninitialize()

if __name__ == "__main__":
    main()
