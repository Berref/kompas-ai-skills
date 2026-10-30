# isScalable - Признак изменения расстояния между линиями штриховки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров стилей объектов ](cf1711377.html) > [Стиль штриховки ](cf1754358.html) > [Стиль штриховки (Интерфейс ksHatchStyleParam) ](kshatchstyleparam.html) > [ksHatchStyleParam - свойства ](cf1712603.html) |  Scroll [ [ [ ](kshatchstyleparam_maychangeangle.html "К следующему разделу")](cf1712603.html "На уровень выше")](kshatchstyleparam_color.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kshatchstyleparam.html)

Тип данных:short.

Значения свойства:

1 | \- по масштабу,  
---|---  
0 | \- по шагу.  
  
Синтаксис Automation:

isScalable = iHatchStyleParam.isScalable | Получить свойство ([* ](1.html))  
---|---  
iHatchStyleParam.isScalable = isScalable | Установить свойство ([* ](1.html))  
isScalable = iHatchStyleParam.GetIsScalable() | Получить свойство ([**](2.html))  
iHatchStyleParam.SetIsScalable( isScalable ) | Установить свойство ([**](2.html))  
  
Примечание:

Шаг используется, если штриховка состоит из сплошных линий (например, металл, неметалл). Масштаб используется, если штриховка состоит из прерывистых линий (например, жидкость); в этом случае изменяется не только расстояние между линиями, но и размер штрихов и расстояние между ними.

Подразделы:

(отсутствуют)
