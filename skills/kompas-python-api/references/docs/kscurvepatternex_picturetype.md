# pictureType - Тип картинки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров стилей объектов ](cf1711377.html) > [Стиль линии ](cf1753270.html) > [Стиль линии с “картинкой” (Интерфейс ksCurvePatternEx) ](kscurvepatternex.html) > [ksCurvePatternEx - свойства ](kscurvepatternex_props.html) |  Scroll [ [ [ ](kscurvepatternex_visibleseg.html "К следующему разделу")](kscurvepatternex_props.html "На уровень выше")](kscurvepatternex_invisibleseg.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvepatternex.html)

Тип данных:short.

Значения свойства:

0 | \- картинка в виде массивов ломаных линий (доступ к массиву с помощью методов [ksCurvePatternEx::GetCurvePicture](kscurvepatternex_getcurvepicture.html) и [ksCurvePatternEx::SetCurvePicture](kscurvepatternex_setcurvepicture.html)),  
---|---  
1 | \- картинка в виде фрагмента (имя фрагмента-источника задается свойством [ksCurvePatternEx::frwName](kscurvepatternex_frwname.html)).  
  
Синтаксис Automation:

pictureType = iCurvePatternEx.pictureType | Получить свойство ([* ](1.html))  
---|---  
iCurvePatternEx.pictureType = pictureType | Установить свойство ([* ](1.html))  
pictureType = iCurvePatternEx.GetPictureType() | Получить свойство ([**](2.html))  
iCurvePatternEx.SetPictureType( pictureType ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
