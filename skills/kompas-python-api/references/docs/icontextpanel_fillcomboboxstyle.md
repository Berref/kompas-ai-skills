# FillComboBoxStyle - Заполнить комбобокс стилей по идентификатору группы команд в манифесте

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с контекстной панелью и меню ](ap2038597.html) > [Интерфейс IContextPanel ](icontextpanel.html) > [IContextPanel - методы ](icontextpanel_methods.html) |  Scroll [ [ [ ](iprocesscontextpanel.html "К следующему разделу")](icontextpanel_methods.html "На уровень выше")](icontextpanel_fillcomboboximage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontextpanel.html)

Синтаксис Automation:

BOOL FillComboBoxStyle( BSTR ComboBoxID, ControlTypeEnum StyleType, VARIANT Styles, long CurrentStyleId );

Синтаксис COM:

HRESULT FillComboBoxStyle( BSTR ComboBoxID, ControlTypeEnum StyleType, VARIANT Styles, long CurrentStyleId, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ComboBoxID | \- строковый идентификатор комбобокса,  
---|---  
StyleType | \- тип стилевого комбобокса,  
Styles | \- список стилей,  
CurrentStyleId | \- номер текущего стиля.  
  
Подразделы:

(отсутствуют)
