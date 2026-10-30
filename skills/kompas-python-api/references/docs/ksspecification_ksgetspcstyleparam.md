# ksGetSpcStyleParam - Получить указатель на интерфейс параметров ksSpcStyleParam или ksSpcTuningStyleParam для указанного стиля спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspctablecolumn.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcsectionname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcStyleParam](ksgetspcstyleparam.html).

Синтаксис Automation:

long ksGetSpcStyleParam (BSTR nameLib,

long numb,

LPDISPATCH par,

long tPar);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификаций (NULL - параметры берутся у текущего документа),  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
tPar | \- тип возвращаемых параметров.  
  
Выходной параметр:

par | \- указатель на интерфейс параметров [ksSpcStyleParam](ksspcstyleparam.html) или [ksSpcTuningStyleParam](ksspctuningstyleparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

tPar = ALLPARAM - интерфейс ksSpcStyleParam,

tPar = SPC_TUNING_PARAM - интерфейс ksSpcTuningStyleParam.

Подразделы:

(отсутствуют)
