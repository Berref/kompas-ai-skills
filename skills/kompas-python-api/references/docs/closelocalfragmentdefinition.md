# CloseLocalFragmentDefinition - Закончить определение локального фрагмента

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](fragmentdefinition.html "К следующему разделу")](frags_fncts.html "На уровень выше")](frags_fncts.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_frw_example.html)

Аналог данной функции при использовании Automation - метод [ksFragment::ksCloseLocalFragmentDefinition](ksfragment_kscloselocalfragmentdefinition.html).

Синтаксис:

int ClosrLocalFragmentDefinition(void);

Возвращаемое значение:

указатель на определение фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1.Все объекты вида, вводимые между функциями [LocalFragmentDefinition](localfragmentdefinition.html) и CloseLocalFragmentDefinition, принадлежат локальному фрагменту.

2.Возвращаемый указатель используется в функциях [InsertFragment](insertfragment.html), [DeleteObj](deleteobj.html).

Подразделы:

(отсутствуют)
