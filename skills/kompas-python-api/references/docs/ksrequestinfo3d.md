# Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) |  Scroll [ [ [ ](ksrequestinfo3d_props.html "К следующему разделу")](ksdocument3d.html "На уровень выше")](ksmassinertiaparam_setbitvectorvalue.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров запроса к системе.

ksRequestInfo3D | \- интерфейс Automation  
---|---  
IRequestInfo | \- интерфейс COM  
  
Примечания:

1\. Данный интерфейс позволяет установить параметры процесса указания местоположения точки или объектов [(UserGetPlacementAndEntity](ksdocument3d_usergetplacementandentity.html)):

2\. Указатель на данный интерфейс можно получить методом [ksDocument3D::GetRequestInfo](ksdocument3d_getrequestinfo.html).

3\. Методами данного интерфейса можно получить/изменить:

•строку подсказки в процессе;

•функцию обратной связи для фильтрации объектов в процессе указания;

•функцию обратной связи процесса.

4\. Методами данного интерфейса можно получить:

•указатель на интерфейс локальной системы координат [ksPlacement,](ksplacement.html)

•указатель на интерфейс [ksEntityCollection](ksentitycollection.html) \- массив указанных в процессе объектов.

Подразделы:

[IRequestInfo - свойства ](ksrequestinfo3d_props.html)

[IRequestInfo - методы ](ksrequestinfo3d_methods.html)

[Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html)

[Массив объектов модели ](ca1789250.html)

[Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html)
