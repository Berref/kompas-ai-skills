# ksInsertFragmentEx - Вставить фрагмент в документ

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](ksreadfragmenttogroup.html "К следующему разделу")](frags_fncts.html "На уровень выше")](insertfragment.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksFragment::ksInsertFragmentEx](ksfragment_ksinsertfragmentex.html).

Синтаксис:

reference ksInsertFragmentEx (reference p,

unsigned char currentLayer,

PlacementParam * par,

unsigned char scaleProjLinesSize);

Входные параметры:

p | \- указатель на фрагмент,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на [структуру параметров привязки](structplacementparam.html)  
scaleProjLinesSize | \- признак масштабирования длины выносных линий размеров: 1 - выносные линии масштабируются, 0 - выносные линии не масштабируются.  
  
Возвращаемое значение:

указатель на вставку фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
