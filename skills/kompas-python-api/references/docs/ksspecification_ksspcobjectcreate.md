# ksSpcObjectCreate - Создать объект спецификации в графическом документе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspcobjectedit.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksspcmassa.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcObjectCreate](ksspcobjectcreate.html).

Синтаксис Automation:

long ksSpcObjectCreate (BSTR nameLib,

long styleNumb,

long secNumb,

long subSecNumb,

double numb,

short typeObj);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
styleNumb | \- номер стиля спецификации в библиотеке,  
secNumb | \- номер раздела,  
subSecNumb | \- номер подраздела,  
numb | \- для базового объекта - тип атрибута, который задан по ключам, или 0, для вспомогательного объекта - номер базового объекта, к которому прикрепляется вспомогательный, либо 0,  
typeObj | \- тип строки спецификации (0- базовый объект, 1 – вспомогательный объект).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Объект спецификации - составной объект. Его создание завершается методом [ksSpecification::ksSpcObjectEnd](ksspecification_ksspcobjectend.html).

2\. Для атрибутов, описанных по ключам, нужно указать тип в numb, потому что типов с одинаковыми ключами может быть несколько.

3\. Параметры nameLib и styleNumb используются только для объектов спецификации в графическом документе.

Подразделы:

(отсутствуют)
