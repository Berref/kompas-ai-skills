# ksSpcObjectCreate - Создать объект спецификации в графическом документе

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcobjectcreatew.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcmassaw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcObjectCreate](ksspecification_ksspcobjectcreate.html).

Синтаксис:

int ksSpcObjectCreate (char * nameLib,

unsigned int styleNumb,

unsigned short secNumb,

unsigned short subSecNumb,

double numb,

unsigned char typeObj);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
styleNumb | \- номер стиля спецификации в библиотеке,  
secNumb | \- номер раздела,  
subSecNumb | \- номер подраздела,  
numb | \- для базового объекта - тип атрибута, который задан по ключам, или 0, для вспомогательного объекта - номер базового объекта, к которому прикрепляется вспомогательный, либо 0,  
typeObj | \- тип строки спецификации (0- базовый объект, 1 – вспомогательный объект).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Объект спецификации - составной объект. Его создание завершается функцией [ksSpcObjectEnd](ksspcobjectend.html).

2\. При использовании Unicode следует использовать функцию [ksSpcObjectCreateW](ksspcobjectcreatew.html).

Подразделы:

(отсутствуют)
