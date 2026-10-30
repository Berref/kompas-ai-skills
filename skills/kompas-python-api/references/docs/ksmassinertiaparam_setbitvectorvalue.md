# SetBitVectorValue - Установить значение битового вектора

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Трехмерное тело ](ca1747705.html) > [МЦХ тела вращения или выдавливания (Интерфейсы ksMassInertiaParam, IMassInertiaParam) ](ksmassinertiaparam.html) > [IMassInertiaParam - методы ](ksmassinertiaparam_methods.html) |  Scroll [ [ [ ](ksrequestinfo3d.html "К следующему разделу")](ksmassinertiaparam_methods.html "На уровень выше")](ksmassinertiaparam_getaxisx.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmassinertiaparam.html)

Синтаксис Automation:

BOOL SetBitVectorValue (long bitVector, BOOL state);

Синтаксис COM:

BOOL SetBitVectorValue (long bitVector, BOOL state);

Входные параметры:

bitVector | \- битовый вектор, состоящий из флагов, определяющих размерность длины, размерность массы и тип тела (тело вращения или выдавливания) для расчета МЦХ,  
---|---  
state | \- состояние битового вектора: TRUE - включен, FALSE - выключен.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
[Размерности и типы тел для расчета МЦХ...](mtypes.html)

Подразделы:

(отсутствуют)
