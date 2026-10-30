# CreateOCX - Создан элемент управления OCX

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyUserControlNotify/IPropertyUserControlNotify ](kspropertyusercontrolnotify.html) > [ksPropertyUserControlNotify - события ](propertyusercontrolnotify_events.html) |  Scroll [ [ [ ](kspropertyusercontrolnotify_destroyocx.html "К следующему разделу")](propertyusercontrolnotify_events.html "На уровень выше")](propertyusercontrolnotify_events.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspropertyusercontrolnotify.html)

Синтаксис Automation:

BOOL CreateOCX (LPDISPATCH iOcx);

Входные параметры:

iOcx | \- указатель на интерфейс IDispatch созданного элемента управления OCX.  
---|---  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. При обработке этого события библиотека может подписаться на события элемента управления OCX для осуществления взаимодействия с ним. Если библиотека подписалась на события элемента управления OCX, то она должна обязательно от них отписаться при получении события[ DestroyOCX](kspropertyusercontrolnotify_destroyocx.html).

2\. Индекс события задан в перечислении событий пользовательского элемента управления [ksPropertyUserControlNotifyEnum](kspropertyusercontrolnotifyenum.html).

Подразделы:

(отсутствуют)
