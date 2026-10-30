# FormStyle - Стиль линий формы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkInsideForm ](imarkinsideform.html) > [IMarkInsideForm - свойства ](imarkinsideform_props.html) |  Scroll [ [ [ ](imarkonline.html "К следующему разделу")](imarkinsideform_props.html "На уровень выше")](imarkinsideform_formheight.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkinsideform.html)

Тип данных: long

Синтаксис Automation:

FormStyle = iObject.FormStyle | Получить свойство([* ](1.html))  
---|---  
iObject.FormStyle = FormStyle | Установить свойство ([* ](1.html))  
FormStyle = iObject.GetFormStyle() | Получить свойство ([**](2.html))  
iObject.SetFormStyle(FormStyle) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FormStyle(&FormStyle) | Получить свойство  
---|---  
iObject->put_FormStyle( FormStyle) | Установить свойство  
  
Примечание:

Стиль формы позволяет задать стиль линий, используемых для отрисовки формы:

Стандартные стили [ksCurveStyleEnum](kscurvestyleenum.html), используемые для отрисовки формы марки:

ksCSNormal | 1 | Основная,  
---|---|---  
ksCSThin | 2 | Тонкая,  
ksCSAxial | 3 | Осевая.  
  
Допустимо задавать и другие стили, в том числе и пользовательские.

Подразделы:

(отсутствуют)
