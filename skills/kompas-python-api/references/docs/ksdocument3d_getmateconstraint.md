# GetMateConstraint - Получить указатель на интерфейс нового временного сопряжения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_getobjparam.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_getlastfeature.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH GetMateConstraint();

Синтаксис COM:

LPMATECONSTRAINT GetMateConstraint();

Возвращаемое значение:

| \- указатель на интерфейс нового сопряжения [ksMateConstraint](ksmateconstraint.html) или [IMateConstraint](ksmateconstraint.html).  
---|---  
  
Примечания:

1\. Сопряжения бывают постоянными и временными. Временные сопряжения, в отличие от постоянных, существуют только в течении процесса указания местоположения или объектов. Процесс запускается методом [ksDocument3D::UserGetPlacementAndEntity](ksdocument3d_usergetplacementandentity.html). Постоянные сопряжения создаются с помощью метода [ksDocument3D::AddMateConstraint](ksdocument3d_addmateconstraint.html).

2\. Для создания временного сопряжения в модели после получения указателя на его интерфейс с помощью данного метода и изменения параметров создаваемого сопряжения используется метод [ksMateConstraint::Create](ksmateconstraint_create.html).

3\. Пример использования методов создания временных и постоянных сопряжений приведен в демонстрационной библиотеке построения модели стандартного изделия (шпильки), которая сохранена в файле STUDS3D.rtw.

Подразделы:

(отсутствуют)
