# Create - Создать временное сопряжение

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html) > [Интерфейсы структуры параметров сопряжения (Интерфейсы ksMateConstraint, IMateConstraint) ](ksmateconstraint.html) > [IMateConstraint - методы ](ksmateconstraint_methods.html) |  Scroll [ [ [ ](ksmateconstraint_getbaseobj.html "К следующему разделу")](ksmateconstraint_methods.html "На уровень выше")](ksmateconstraint_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmateconstraint.html)

Синтаксис Automation:

BOOL Create();

Синтаксис COM:

BOOL Create();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Сопряжения бывают постоянными и временными. Временные сопряжения, в отличие от постоянных, существуют только в течении процесса указания местоположения или объектов. Процесс запускается методом [ksDocument3D::UserGetPlacementAndEntity](ksdocument3d_usergetplacementandentity.html). Постоянные сопряжения создаются с помощью метода [ksDocument3D::AddMateConstraint](ksdocument3d_addmateconstraint.html).

2\. Данный метод необходимо вызвать для создания временного сопряжения в модели после создания интерфейса с помощью метода [ksDocument3D::GetMateConstraint](ksdocument3d_getmateconstraint.html) и изменения параметров создаваемого сопряжения. Если до вызова данного метода параметры не изменены, сопряжение создается с параметрами, принятыми по умолчанию.

3\. Пример использования методов создания временных и постоянных сопряжений приведен в демонстрационной библиотеке построения модели стандартного изделия (шпильки), которая сохранена в файле STUDS3D.rtw.

Подразделы:

(отсутствуют)
