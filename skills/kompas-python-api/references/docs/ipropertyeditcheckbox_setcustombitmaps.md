# SetCustomBitmaps - Установить собственное изображение кнопки в разных состояниях

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyEditCheckBox ](ipropertyeditcheckbox.html) > [IPropertyEditCheckBox - методы ](ipropertyeditcheckbox_methods.html) |  Scroll [ [ [ ](ipropertypreviewtext.html "К следующему разделу")](ipropertyeditcheckbox_methods.html "На уровень выше")](ipropertyeditcheckbox_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyeditcheckbox.html)

Синтаксис Automation:

void SetCustomBitmaps( VARIANT IdUnchecked,

VARIANT IdChecked,

VARIANT IdIndeterminate,

VARIANT HInstance );

Синтаксис COM:

HRESULT SetCustomBitmaps( VARIANT IdUnchecked,

VARIANT IdChecked,

VARIANT IdIndeterminate,

VARIANT HInstance,

void * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

IdUnchecked | \- значок ненажатого состояния,  
---|---  
IdChecked | \- значок нажатого состояния,  
IdIndeterminate | \- значок неопределенного состояния,  
HInstance | \- dll-модуль с ресурсами значков.  
  
Примечания:

1\. Значки могут быть заданы в виде идентификаторов в ресурсе dll-модуля (тип данных long) или в виде полного пути к bmp-файлу значка (тип данных BSTR). Обязательным является задание значка для ненажатого состояния idUnchecked, остальные могут быть не заданы.

2\. Все значения переменных должны быть одного типа (или long, или BSTR).

3\. Если значки задаются в виде идентификатора, то обязательно должен быть задан dll-модуль, в ресурсах которого лежат эти значки. Модуль с ресурсами значков hInstance может быть задан в виде HINSTANCE (тип значения long) или полного пути к файлу (тип значения BSTR) dll-модуля.

Подразделы:

(отсутствуют)
