# ResModule - Модуль с ресурсом рисунка кнопки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyFileName ](ipropertyfilename.html) > [IPropertyFileName - свойства ](ipropertyfilename_props.html) |  Scroll [ [ [ ](ipropertyfilename_width.html "К следующему разделу")](ipropertyfilename_props.html "На уровень выше")](ipropertyfilename_readonly.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertyfilename.html)

Тип данных: VARIANT (long или BSTR).

Синтаксис Automation:

ResModule = iObject.ResModule | Получить свойство ([* ](1.html))  
---|---  
iObject.ResModule = ResModule | Установить свойство ([* ](1.html))  
ResModule = iObject.GetResModule() | Получить свойство([**](2.html))  
iObject.SetResModule (ResModule) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ResModule (ResModule) | Получить свойство  
---|---  
iObject->put_ResModule (ResModule) | Установить свойство  
  
Значения свойства:

HINSTANCE (тип значения long), |   
---|---  
полный путь к файлу (тип значения BSTR) dll модуля, в котором находятся все необходимые ресурсы. |   
  
Примечание:

Данное свойство позволяет установить или получить dll-модуль, в котором находится рисунок для кнопки (см. [Bitmap](ipropertyfilename_bitmap.html)).

Подразделы:

(отсутствуют)
