# Unload - Выгрузить компонент

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_unloadex.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_transferobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL Unload( BOOL full )

Синтаксис COM:

HRESULT Unload( BOOL full, BOOL * result );

Входные параметры:

full | TRUE - выгрузить полностью, FALSE - выгрузить частично.  
---|---  
  
Возвращаемое значение:

TRUE | \- компонент успешно загружен,  
---|---  
FALSE | \- компонент не загружен.  
  
Примечание:

Метод позволяет осуществить выгрузку компонента. Для верхнего компонента не используется.

Подразделы:

(отсутствуют)
