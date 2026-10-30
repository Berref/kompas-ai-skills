# windowNeedRebuild - Свойство необходимости перерисовки окна документа

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_methods.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_treeneedrebuild.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- надо перерисовывать,  
---|---  
FALSE | \- не надо перерисовывать.  
  
Синтаксис:

windowNeedRebuild = object.windowNeedRebuild | Получить свойство ([* ](1.html))  
---|---  
object.windowNeedRebuild = windowNeedRebuild | Установить свойство ([* ](1.html))  
windowNeedRebuild = object.GetWindowNeedRebuild() | Получить свойство ([**](2.html))  
object.SetWindowNeedRebuild(windowNeedRebuild) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство позволяет временно отключить перерисовку окна документа.

Используется для ускорения создания, удаления или изменения группы объектов.

Подразделы:

(отсутствуют)
