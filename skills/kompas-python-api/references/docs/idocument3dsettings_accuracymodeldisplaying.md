# AccuracyModelDisplaying - Точность отрисовки

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IDocument3DSettings ](idocument3dsettings.html) > [IDocument3DSettings - свойства ](idocument3dsettings_props.html) |  Scroll [ [ [ ](idocument3dsettings_decimaldelimitertype.html "К следующему разделу")](idocument3dsettings_props.html "На уровень выше")](idocument3dsettings_accuracymassproperties.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocument3dsettings.html)

Тип данных: double

Синтаксис Automation:

AccuracyModelDisplaying = Object.AccuracyModelDisplaying | Получить свойство ([* ](1.html))  
---|---  
Object.AccuracyModelDisplaying = AccuracyModelDisplaying | Установить свойство ([* ](1.html))  
AccuracyModelDisplaying = Object.GetAccuracyModelDisplaying() | Получить свойство ([**](2.html))  
Object.SetAccuracyModelDisplaying (AccuracyModelDisplaying) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object->get_AccuracyModelDisplaying (&AccuracyModelDisplaying) | Получить свойство,  
---|---  
Object->put_AccuracyModelDisplaying (AccuracyModelDisplaying) | Установить свойство.  
  
Примечание:

Свойство позволяет увеличить или уменьшить точность аппроксимации криволинейных ребер и линий очерка модели отрезками прямых линий, а криволинейных поверхностей — треугольниками. Чем выше точность, тем более «гладким» выглядит изображение и тем больше времени требуется на расчеты.

Подразделы:

(отсутствуют)
