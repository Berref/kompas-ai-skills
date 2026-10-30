# embeded - Признак внедрения растра или ссылки на него

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров графических примитивов ](cd1743949.html) > [Растровая вставка (Интерфейс ksRasterParam) ](ksrasterparam.html) > [ksRasterParam - свойства ](ksrasterparam_props.html) |  Scroll [ [ [ ](ksrasterparam_filename.html "К следующему разделу")](ksrasterparam_props.html "На уровень выше")](ksrasterparam_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrasterparam.html)

Тип данных:BOOL.

Значения свойства:

TRUE | \- внедрять данные в объект,  
---|---  
FALSE | \- связывать объект с файлом-источником данных на диске.  
  
Синтаксис Automation:

embeded = iRasterParam.embeded | Получить свойство ([* ](1.html))  
---|---  
iRasterParam.embeded = embeded | Установить свойство ([* ](1.html))  
embeded = iRasterParam.GetEmbeded() | Получить свойство ([**](2.html))  
iRasterParam.SetEmbeded( embeded ) | Установить свойство ([**](2.html))  
  
Примечание:

Значение FALSE в данный момент не используется (связь растрового объекта с файлом на диске в КОМПАС-ГРАФИК не реализована).

Подразделы:

(отсутствуют)
