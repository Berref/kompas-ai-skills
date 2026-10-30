# Image - Растровый рисунок на вкладке

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyTab ](ipropertytab.html) > [IPropertyTab - свойства ](ipropertytab_props.html) |  Scroll [ [ [ ](ipropertytab_propertycontrols.html "К следующему разделу")](ipropertytab_props.html "На уровень выше")](ipropertytab_expanded.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertytab.html)

Тип данных: VARIANT (long или BSTR).

Значения свойства:

HINSTANCE (тип значения long) | \- полный путь к файлу (тип значения BSTR) dll модуля в котором находятся все необходимые ресурсы.  
---|---  
  
Синтаксис Automation:

Image = iObject.Image | Получить свойство ([* ](1.html))  
---|---  
iObject.Image = Image | Установить свойство ([* ](1.html))  
Image = iObject.GetImage() | Получить свойство([**](2.html))  
iObject.SetImage(Image) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Image(&Image) | Получить свойство  
---|---  
iObject->put_Image(Image) | Установить свойство  
  
Примечание:

Свойство позволяет получить или установить битмап на закладке.

Битмап можно задать в виде идентификатора в файле ресурсов (тип данных long) или полного пути к bmp-файлу значка (тип данных BSTR).

Подразделы:

(отсутствуют)
