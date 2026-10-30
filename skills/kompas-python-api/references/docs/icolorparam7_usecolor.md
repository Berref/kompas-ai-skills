# UseColor - Используемый цвет

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Свойства цвета объекта ](bc2297422.html) > [Интерфейс IColorParam7 ](icolorparam7.html) > [IColorParam7 - свойства ](icolorparam7_props.html) |  Scroll [ [ [ ](icolorparam7_methods.html "К следующему разделу")](icolorparam7_props.html "На уровень выше")](icolorparam7_transparency.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolorparam7.html)

Тип данных: из перечисления [UseColor](usecolor.html)

Синтаксис Automation:

UseColor = Object.UseColor | Получить свойство ([* ](1.html))  
---|---  
Object.UseColor = UseColor | Установить свойство ([* ](1.html))  
UseColor = Object.GetUseColor() | Получить свойство ([**](2.html))  
Object.SetUseColor( UseColor ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_UseColor( &UseColor ) | Получить свойство  
---|---  
Object.put_UseColor( UseColor ) | Установить свойство  
  
Использование свойства для объектов:

Верхний компонент  
---  
useColorOur | 0 | собственный цвет  
Вставка в сборку  
useColorOur | 0 | собственный цвет  
useColorOwner | 1 | цвет сборки  
useColorSource | 2 | цвет источника  
Грань, операции, объекты детали  
useColorOur | 0 | собственный цвет  
useColorSource | 2 | цвет источника  
Операции: вырезать выдавливанием, скругление, фаска, отверстие, оболочка, сечение плоскостью, сечение эскизом, удалить грань  
useColorOur | 0 | собственный цвет  
useColorOwner | 1 | цвет сборки  
useColorSource | 2 | цвет источника  
Тело  
useColorOur | 0 | собственный цвет  
useColorSource | 2 | цвет источника  
  
Примечание:

В случае ошибки возвращается useColorUnknown.

Подразделы:

(отсутствуют)
