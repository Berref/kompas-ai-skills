# BeginCreatePartFromFile - Начало создания компонента в сборке (до диалога выбора имени)

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocument3DNotify7 ](ksdocument3dnotify7.html) > [ksDocument3DNotify7 - события ](ksdocument3dnotify7_events.html) |  Scroll [ [ [ ](ksdocument3dnotify7_beginrebuild.html "К следующему разделу")](ksdocument3dnotify7_events.html "На уровень выше")](ksdocument3dnotify7_beginchoicematerial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotify7.html)

Синтаксис:

VARIANT_BOOL BeginCreatePartFromFile (VARIANT_BOOL typeDoc, LPDISPATCH * plane);

Входные параметры:

typeDoc | TRUE - вставить деталь,  
---|---  
FALSE - вставить сборку,  
plane | \- плоскость типа [IModelObject](imodelobject.html), на которой создается компонент.  
  
Возвращаемое значение:

TRUE | \- установить компонент в сборку,  
---|---  
FALSE | \- установка компонента в сборку запрещена.  
  
Подразделы:

(отсутствуют)
