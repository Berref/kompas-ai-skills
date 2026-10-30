# МЦХ тела вращения или выдавливания (Интерфейсы ksMassInertiaParam, IMassInertiaParam)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Трехмерное тело ](ca1747705.html) |  Scroll [ [ [ ](ksmassinertiaparam_props.html "К следующему разделу")](ca1747705.html "На уровень выше")](ksintersectionresult_getintersectiontype.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров расчета массово-центровочных характеристик.

ksMassInertiaParam | \- интерфейс Automation  
---|---  
IMassInertiaParam | \- интерфейс COM  
  
Аналог данного интерфейса при использовании API экспортных функций - [MassInertiaParamStruct](structmassinertiaparam.html).

Примечание:

1\. Указатель на интерфейс можно получить при помощи метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html). Аналогом интерфейса при использовании API экспортных функций является [MassInertiaParamStruct](structmassinertiaparam.html). Наполнение данными производится в методе [ksMathematic2D::ksCalcMassInertiaProperties](ksmathematic2d_kscalcmassinertiaproperties.html), аналог экспортной функции [ksCalcMassInertiaProperties](kscalcmassinertiaproperties.html).

2\. В трехмерной автоматизации указатель на интерфейс ksMassInertiaParam можно получить при помощи метода [ksPart::CalcMassInertiaProperties](kspart_calcmassinertiaproperties.html) или [ksBody::MassInertiaParam](ksbody_massinertiaparam.html). В 3D COM указатель на интерфейс IMassInertiaParam получается методом [IPart::CalcMassInertiaProperties](kspart_calcmassinertiaproperties.html) или [IBody::MassInertiaParam](ksbody_massinertiaparam.html).

3\. Размерность длины и размерность массы, возвращаемых интерфейсом, данных находятся в интервале [ST_MIX_MM..ST_MIX_KG]. Она устанавливается при получении интерфейса, либо через [SetBitVectorValue](ksmassinertiaparam_setbitvectorvalue.html).

Смотрите также:[KompasObject](kompasobject.html)

Подразделы:

[IMassInertiaParam - свойства ](ksmassinertiaparam_props.html)

[IMassInertiaParam - методы ](ksmassinertiaparam_methods.html)
