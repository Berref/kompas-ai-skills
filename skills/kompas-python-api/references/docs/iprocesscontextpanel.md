# Интерфейс IProcessContextPanel

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с контекстной панелью и меню ](ap2038597.html) |  Scroll [ [ [ ](iprocesscontextpanel_propers.html "К следующему разделу")](ap2038597.html "На уровень выше")](icontextpanel_fillcomboboxstyle.html "К предыдущему разделу")  
---|---  
  
Интерфейс контекстной панели процесса.

Иерархия:

IDispatch

[IProcessContextPanel](iprocesscontextpanel.html)

Примечание:

Интерфейс используется в событии [ksPropertyManagerNotify::FillContextPanel](kspropertymanagernotify_fillcontextpanel.html)

Интерфейс позволяет заменить обычное меню процесса на панель которая может содержать контролы Панели свойств.

Для использования контекстной панели в процессе нужно в событии [ksPropertyManagerNotify::GetContextMenuType](kspropertymanagernotify_getcontextmenutype.html) вернуть константу ksProcessContextPanel из перечисления [ksProcessContextMenuType](ksprocesscontextmenutype.html).

Подразделы:

[IProcessContextPanel - методы ](iprocesscontextpanel_propers.html)
