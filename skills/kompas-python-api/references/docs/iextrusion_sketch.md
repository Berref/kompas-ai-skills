# Sketch - Эскиз

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - свойства ](iextrusion_props.html) |  Scroll [ [ [ ](iextrusion_methods.html "К следующему разделу")](iextrusion_props.html "На уровень выше")](iextrusion_extrusiontype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Тип данных: указатель на интерфейс эскиза [ISketch](isketch.html)

Синтаксис Automation:

Sketch = iObject.Sketch; | Получить свойство ([* ](1.html))  
---|---  
iObject.Sketch = Sketch; | Установить свойство ([* ](1.html))  
Sketch = iObject.GetSketch(); | Получить свойство ([**](2.html))  
iObject.SetSketch( Sketch ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Sketch( &Sketch ); | Получить свойство  
---|---  
iObject->put_Sketch( Sketch ); | Установить свойство  
  
Примечание:

Свойство позволяет установить новый эскиз для операции и получить указатель на эскиз.

Подразделы:

(отсутствуют)
