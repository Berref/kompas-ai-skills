# CalcMassInertiaProperties - Определить массово-центровочные характеристики

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getmateconstraintobjects.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getmass.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH CalcMassInertiaProperties (long bitVector);

Синтаксис COM:

LPMASSINERTIAPARAM CalcMassInertiaProperties (unsigned int bitVector);

Входной параметр:

bitVector | \- определяет размерность длины, размерность массы.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksMassInertiaParam](ksmassinertiaparam.html) или [IMassInertiaParam](ksmassinertiaparam.html).  
---|---  
  
Примечание:

Варианты значений для задания значений bitVector находятся в интервале [ST_MIX_MM..ST_MIX_KG]

Пример:

(метры|кг - ST_MIX_M|ST_MIX_KG)

Подразделы:

(отсутствуют)
