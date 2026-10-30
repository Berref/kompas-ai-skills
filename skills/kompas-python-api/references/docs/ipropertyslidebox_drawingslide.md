# DrawingSlide - Отображаемый слайд

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySlideBox ](ipropertyslidebox.html) > [IPropertySlideBox - свойства ](ipropertyslidebox_props.html) |  Scroll [ [ [ ](ipropertyslidebox_height.html "К следующему разделу")](ipropertyslidebox_props.html "На уровень выше")](ipropertyslidebox_checkboxvisibility.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyslidebox.html)

Тип данных: VARIANT (long или BSTR).

Синтаксис Automation:

DrawingSlide = iObject.DrawingSlide | Получить свойство ([* ](1.html))  
---|---  
iObject.DrawingSlide = DrawingSlide | Установить свойство ([* ](1.html))  
DrawingSlide = iObject.GetDrawingSlide() | Получить свойство([**](2.html))  
iObject.SetDrawingSlide (DrawingSlide) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawingSlide (&DrawingSlide) | Получить свойство  
---|---  
iObject->put_DrawingSlide (DrawingSlide) | Установить свойство  
  
Значение свойства:

Идентификатор или указатель на группу, документ (тип значения long), или полный путь к файлу (тип значения BSTR) документа или текстового файла с описанием слайда.  
---  
  
Примечание:

Тип отображаемого объекта определяется свойством [SlideType](ipropertyslidebox_slidetype.html).

Подразделы:

(отсутствуют)
