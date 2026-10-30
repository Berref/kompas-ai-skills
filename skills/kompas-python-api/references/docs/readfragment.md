# ReadFragment - Прочитать фрагмент в текущий вид

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](readfragmentw.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksviewgetdensityandmaterialw.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_frw_example.html)

Аналог данной функции при использовании Automation - метод [ksFragment::ksReadFragment](ksfragment_ksreadfragment.html).

Синтаксис:

int ReadFragment (char *fileName,

unsigned char currentLayer,

PlacementParam * par);

Входные параметры:

fileName | \- имя фрагмента,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на [структуру параметров привязки.](structplacementparam.html)  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Допускается задание имени файла следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец",

где

c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя фрагмента.

В этом случае фрагмент берется из библиотеки фрагментов.

2\. При использовании Unicode следует использовать функцию [ReadFragmentW](readfragmentw.html).

Подразделы:

(отсутствуют)
