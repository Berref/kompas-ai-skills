# ksSetTuningSpcStyleParam - Установить параметры настроек спецификации документа

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspcchangevalue.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcperformancename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetTuningSpcStyleParam](kssettuningspcstyleparam.html).

Синтаксис Automation:

long ksSetTuningSpcStyleParam(long index, LPDISPATCH par);

Входные параметры:

index | \- индекс описания спецификации в документе,  
---|---  
par | \- указатель на интерфейс [ksSpcTuningStyleParam](ksspctuningstyleparam.html) структуры параметров настроек спецификации.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если index = -1, то для текущего описания спецификации.

2\. Для документа спецификации настройки можно изменить всегда.

3\. Для графического документа в случае, если документ подключен к спецификации или включен режим "Спецификация на листе".

4\. Для документа трехмерного объекта в случае, если документ подключен к спецификации.

Подразделы:

(отсутствуют)
