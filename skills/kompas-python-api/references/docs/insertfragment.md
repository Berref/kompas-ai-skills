# InsertFragment - Вставить фрагмент в документ

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](ksinsertfragmentex.html "К следующему разделу")](frags_fncts.html "На уровень выше")](fragmentdefinitionw.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_frw_example.html)

Замечание:

Функция устарела, рекомендуется использовать вместо нее функцию [ksInsertFragmentEx](ksinsertfragmentex.html).

Аналог данной функции при использовании Automation - метод [ksFragment::ksInsertFragment](ksfragment_ksinsertfragment.html).

Синтаксис:

reference InsertFragment (reference p,

unsigned char currentLayer,

PlacementParam * par);

Входные параметры:

p | \- указатель на фрагмент,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на [структуру параметров привязки](structplacementparam.html)  
  
Возвращаемое значение:

указатель на вставку фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
