# BaseUserOrientation - Матрица базовой ориентации модели

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjectionManager](iviewprojectionmanager.html) > [IViewProjectionManager - свойства](iviewprojectionmanager_propers.html) |  Scroll [ [ [ ](iviewprojectionmanager_count.html "К следующему разделу")](iviewprojectionmanager_propers.html "На уровень выше")](iviewprojectionmanager_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojectionmanager.html)

Тип данных: VARIANT

Синтаксис Automation:

BaseUserOrientation = Object.BaseUserOrientation | Получить свойство ([* ](1.html))  
---|---  
Object.BaseUserOrientation = BaseUserOrientation | Установить свойство ([* ](1.html))  
BaseUserOrientation = Object.GetBaseUserOrientation() | Получить свойство ([**](2.html))  
Object.SetBaseUserOrientation( BaseUserOrientation ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseUserOrientation( &BaseUserOrientation ) | Получить свойство  
---|---  
Object.put_BaseUserOrientation( BaseUserOrientation ) | Установить свойство  
  
Примечание

1.Элементы матрицы возвращаются в виде одномерного массива из 16 элементов SafeAttray типа (VT_ARRAY | VT_R8).. Матрица имеет размер 4х4.

2.Метод позволяет получить матрицу, которая может использоваться для отображения вида спереди.

3.По умолчанию используется единичная матрица без смещения.

Подразделы:

(отсутствуют)
