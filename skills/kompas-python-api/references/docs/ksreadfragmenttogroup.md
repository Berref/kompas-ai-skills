# ksReadFragmentToGroup - Вставить фрагмент россыпью во временную группу

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](ksreadfragmenttogroupex.html "К следующему разделу")](frags_fncts.html "На уровень выше")](ksinsertfragmentex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksreadfragmenttogroup_example.html)

Замечание:

Функция устарела, рекомендуется использовать вместо нее функцию [ksReadFragmentToGroupEx](ksreadfragmenttogroupex.html).

Аналог данной функции при использовании Automation - метод [ksFragment::ksReadFragmentToGroup](ksfragment_ksreadfragmenttogroup.html).

Синтаксис:

reference ksReadFragmentToGroup (char * fileName,

unsigned char curentLayer,

PlacementParam * par);

Входные параметры:

fileName | \- имя фрагмента,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на [структуру параметров привязки](structplacementparam.html).  
  
Возвращаемое значение:

указатель на временную группу | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Допускается задание имени файла следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец",

где:

c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя фрагмента.

В этом случае фрагмент берется из библиотеки фрагментов.

Подразделы:

(отсутствуют)
