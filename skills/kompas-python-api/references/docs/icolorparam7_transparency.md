# Transparency - Прозрачность

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Свойства цвета объекта ](bc2297422.html) > [Интерфейс IColorParam7 ](icolorparam7.html) > [IColorParam7 - свойства ](icolorparam7_props.html) |  Scroll [ [ [ ](icolorparam7_usecolor.html "К следующему разделу")](icolorparam7_props.html "На уровень выше")](icolorparam7_specularity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolorparam7.html)

Тип данных: double

Значения свойства:

| \- [Прозрачность](transparency.html) (от 0 до 1).  
---|---  
  
Синтаксис Automation:

Transparency = Object.Transparency | Получить свойство ([* ](1.html))  
---|---  
Object.Transparency = Transparency | Установить свойство ([* ](1.html))  
Transparency = Object.GetTransparency() | Получить свойство ([**](2.html))  
Object.SetTransparency (Transparency) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Transparency( &Transparency ) | Получить свойство  
---|---  
Object.get_Transparency( &Transparency ) | Установить свойство  
  
Примечание:

Этот параметр характеризует способность поверхности пропускать падающий на нее свет. Если значение этого параметра равно 1 (или 100%), то поверхность совершенно непрозрачная. При моделировании деталей из стекла, органического стекла, слюды, бесцветного полиэтилена и подобных материалов значение прозрачности выбирают из диапазона между 0 и 1.

Если значение этого параметра равно 0,5 (или 50%), то поверхность полупрозрачная.

Если значение этого параметра равно 0, то поверхность полностью прозрачная. Такая поверхность невидима.

Подразделы:

(отсутствуют)
