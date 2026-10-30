# ksGetSpcTableColumn - Получить количество колонок для стиля спецификации в текущем документе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgettuningspcstyleparam.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcstyleparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcTableColumn](ksgetspctablecolumn.html).

Синтаксис Automation:

long ksGetSpcTableColumn (BSTR nameLib,

long numb,

short additioanalCol);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификаций,  
---|---  
numb | \- номер стиля в библиотеке,  
additioanalCol | \- признак колонок: 0 - видимые колонки таблицы спецификации, 1 - дополнительные колонки.  
  
Возвращаемое значение:

| \- количество колонок для стиля спецификации в текущем документе.  
---|---  
  
Примечания:

1\. Если документ - спецификация, то параметры nameLib и numb не используются.

2\. Если количество исполнений больше числа колонок "количество" в бланке спецификации, то количество колонок выдается с учетом всех исполнений.

Подразделы:

(отсутствуют)
