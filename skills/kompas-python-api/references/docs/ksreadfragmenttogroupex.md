# ksReadFragmentToGroupEx - Вставить фрагмент россыпью во временную группу

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](ksreadfragmenttogroupexw.html "К следующему разделу")](frags_fncts.html "На уровень выше")](ksreadfragmenttogroup.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksFragment::ksReadFragmentToGroupEx](ksfragment_ksreadfragmenttogroupex.html).

Синтаксис:

reference ksReadFragmentToGroupEx (char * fileName,

unsigned char curentLayer,

PlacementParam * par.

unsigned char scaleProjLinesSize);

Входные параметры:

fileName | \- имя фрагмента,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на [структуру параметров привязки,](structplacementparam.html)  
scaleProjLinesSize | \- признак масштабирования длины выносных линий размеров: 1 - выносные линии масштабируются, 0 - выносные линии не масштабируются.  
  
Возвращаемое значение:

указатель на временную группу | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Допускается задание имени файла следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец", где

– c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

– |детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

– фланец - имя фрагмента.

В этом случае фрагмент берется из библиотеки фрагментов.

2\. При использовании Unicode следует использовать функцию [ksReadFragmentToGroupExW](ksreadfragmenttogroupexw.html).

Подразделы:

(отсутствуют)
