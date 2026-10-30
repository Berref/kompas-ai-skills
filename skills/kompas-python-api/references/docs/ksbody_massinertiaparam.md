# MassInertiaParam - Получить указатель на интерфейс массово-центровочных характеристик

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [Трехмерное тело (Интерфейсы ksBody, Body) ](ksbody.html) > [IBody - методы ](ksbody_methods.html) |  Scroll [ [ [ ](ksbodyparts.html "К следующему разделу")](ksbody_methods.html "На уровень выше")](ksbody_issolid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbody.html)

Синтаксис Automation:

LPDISPATCH CalcMassInertiaProperties (long bitVector);

Синтаксис COM:

LPMASSINERTIAPARAM CalcMassInertiaProperties (unsigned int bitVector);

Входной параметр:

bitVector | \- определяет размерность длины, размерность массы.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksIMassInertiaParam](ksmassinertiaparam.html) или [IMassInertiaParam](ksmassinertiaparam.html).  
---|---  
  
Примечания:

Варианты значений для задания значений bitVector находятся в интервале [ST_MIX_MM..ST_MIX_KG]

Пример:

(метры|кг - ST_MIX_M|ST_MIX_KG).

Подразделы:

(отсутствуют)
