# ksChoiceAttrTypes - Выбрать указанный пользователем в диалоге тип атрибута из библиотеки или документа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_kscreateattr.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kschoiceattr3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ChoiceAttrTypes](choiceattrtypes.html).

Синтаксис Automation:

double ksChoiceAttrTypes (BSTR libName);

Входной параметр:

libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется из текущего документа.  
---|---  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Диалог "привязан" к главному окну.

Подразделы:

(отсутствуют)
