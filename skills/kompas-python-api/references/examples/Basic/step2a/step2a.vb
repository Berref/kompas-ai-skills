Option Strict Off
Option Explicit On

Imports System.Reflection
Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), System.Runtime.InteropServices.ProgId("StepsVB.Step2a")>
Public Class Step2a
  ' step2a - Массив неопределенной длины

  ' 1. Массив строк                           - StrIndefiniteArray
  ' 2. Массив математических точек            - PointIndefiniteArray
  ' 3. Массив строк объекта "текст"           - TextIndefiniteArray
  ' 4. Массив колонок типа атрибута           - AttrIndefiniteArray
  ' 5. Массив полилиний                       - PolyLineArray
  ' 6. Массив габаритных прямоугольников      - RectArray
  ' 7. Массив структур пользователя           - UserDataArray
  ' 8. Массив экземпляров класса пользователя - UserClassArray

  Public Kompas As Kompas6API5.Application ' Интерфейс KompasObject

  ' Определить имя библиотеки

  Public Function GetLibraryName() As String
    GetLibraryName = "Массив неопределенной длины" ' Имя библиотеки
  End Function

  ' Массив предназначен для хранения математических точек типа MathPointParam

  Sub PointIndefiniteArray(ByRef doc As Kompas6API5.Document2D)
    Dim i As Object
    If doc Is Nothing Then ' Если интерфейс не получен - выходим
      Exit Sub ' и ничего не делаем
    End If

    Dim mathPar As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    ' Создать интерфейс параметров математической точки
    mathPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

    Dim arr As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива математических точек
    arr = Kompas.GetDynamicArray(POINT_ARR)

    ' Интерфейсы созданы
    Dim n As Short
    If (Not mathPar Is Nothing) And (Not arr Is Nothing) Then
      ' Наполнить массив математических точек
      mathPar.x = 10 ' Координаты точки
      mathPar.y = 10
      arr.ksAddArrayItem(-1, mathPar) ' Добавим 1-ю точку, элемент добавляется в конец массива

      mathPar.x = 20 ' Координаты точки
      mathPar.y = 20
      arr.ksAddArrayItem(-1, mathPar) ' Добавим 2-ю точку, элемент добавляется в конец массива

      mathPar.x = 30 ' Координаты точки
      mathPar.y = 30
      arr.ksAddArrayItem(-1, mathPar) ' Добавим 3-ю точку, элемент добавляется в конец массива

      Kompas.ksMessageBoxResult() ' Результат выполнения

      n = arr.ksGetArrayCount ' Количество элементов в массиве математических точек
      Kompas.ksMessage("n = " & n) ' Вывод

      For i = 0 To n - 1 ' Просмотрим массив математических точек
        arr.ksGetArrayItem(i, mathPar) ' Получить значение элемента массива
        Kompas.ksMessage("i = " & i & " x = " & mathPar.x & " y = " & mathPar.y) ' Вывод
      Next i

      ' Заменим параметры 1-го элемента массива математических точек
      mathPar.x = 50 ' Координаты точки
      mathPar.y = 50
      arr.ksSetArrayItem(1, mathPar) ' Задать новые параметры 1-му элементу

      ' Заменим параметры 0-го элемента массива математических точек
      mathPar.x = 60 ' Координаты точки
      mathPar.y = 60
      arr.ksSetArrayItem(0, mathPar) ' Задать новые параметры 0-му элементу

      n = arr.ksGetArrayCount ' Количество элементов в массиве математических точек

      For i = 0 To n - 1 ' Просмотрим массив математических точек
        arr.ksGetArrayItem(i, mathPar) ' Получить значение элемента массива
        Kompas.ksMessage("i = " & i & " x = " & mathPar.x & " y = " & mathPar.y) ' Вывод
      Next i

      arr.ksDeleteArray() ' Удалить динамический массив математических точек
    End If

    Kompas.ksMessageBoxResult() ' Результат выполнения

  End Sub

  ' Массив предназначен для хранения строк

  Sub StrIndefiniteArray(ByRef doc As Kompas6API5.Document2D)
    Dim i As Object
    If doc Is Nothing Then ' Если интерфейс не получен - выходим
      Exit Sub ' и ничего не делаем
    End If

    Dim arr As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива строк
    arr = Kompas.GetDynamicArray(CHAR_STR_ARR)

    Dim charBuf As Kompas6API5.Char255 ' Интерфейс ksChar255
    ' Создать интерфейс строки длиной 255 символов
    charBuf = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)

    ' Интерфейсы созданы
    Dim n As Short
    If (Not charBuf Is Nothing) And (Not arr Is Nothing) Then
      charBuf.str = "12345" ' Наполним строку
      arr.ksAddArrayItem(-1, charBuf) ' Добавим 1-ю строку, элемент добавляется в конец массива

      charBuf.str = "67890" ' Наполним строку
      arr.ksAddArrayItem(-1, charBuf) ' Добавим 2-ю строку, элемент добавляется в конец массива

      charBuf.str = "qwerty" ' Наполним строку
      arr.ksAddArrayItem(-1, charBuf) ' Добавим 3-ю строку, элемент добавляется в конец массива

      Kompas.ksMessageBoxResult() ' Результат выполнения

      n = arr.ksGetArrayCount ' Количество элементов в массиве строк

      Kompas.ksMessage("n = " & n) ' Вывод

      For i = 0 To n - 1 ' Просмотрим массив строк
        arr.ksGetArrayItem(i, charBuf) ' Получить значение элемента массива
        Kompas.ksMessage(charBuf.str) ' Вывод
      Next i

      arr.ksExcludeArrayItem(1) ' Исключить из массива 1-й элемент
      n = arr.ksGetArrayCount ' Количество элементов в массиве строк

      For i = 0 To n - 1 ' Просмотрим массив строк
        arr.ksGetArrayItem(i, charBuf) ' Получить значение элемента массива
        Kompas.ksMessage(charBuf.str) ' Вывод
      Next i

      arr.ksDeleteArray() ' Удалить динамический массив строк
    End If

    Kompas.ksMessageBoxResult() ' Результат выполнения
  End Sub

  '  Массив предназначен для создания и получения параетров параграфа текста,
  '  состоящего из   нескольких строк, которые в свою очередь
  '  состоят из компонент, с разными параметрами
  '  ( с наклоном, с утолщением, спецзнаки и т. д.)

  Sub TextIndefiniteArray(ByRef doc As Kompas6API5.Document2D)
    Dim j As Object
    Dim i As Object
    If doc Is Nothing Then ' Если интерфейс не получен - выходим
      Exit Sub ' и ничего не делаем
    End If

    Dim itemPar As Kompas6API5.TextItemParam ' Интерфейс ksTextItemParam
    ' Структура параметров компоненты строки текста
    itemPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)

    Dim linePar As Kompas6API5.TextLineParam ' Интерфейс ksTextLineParam
    ' Структура параметров строки текста
    linePar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)

    ' Интерфейсы созданы
    Dim itemArr As Kompas6API5.DynamicArray
    Dim font As Kompas6API5.TextItemFont
    Dim lineArr As Kompas6API5.DynamicArray
    Dim n As Short
    Dim n1 As Short ' Интерфейс ksDynamicArray ' Интерфейс ksTextItemFont
    If (Not itemPar Is Nothing) And (Not linePar Is Nothing) Then
      itemPar.Init() ' Инициализация параметров
      linePar.Init() ' Инициализация параметров

      itemArr = linePar.GetTextItemArr ' Массив компонет текстовой строки

      font = itemPar.GetItemFont ' Параметры шрифта

      ' Создаем 1-ю компоненту текста
      font.height = 10 ' Высота текста
      font.ksu = 1 ' Cужение текста
      font.color = 1000 ' Цвет
      font.bitVector = 1 ' Битовый вектор ( наклон, толщина, подчеркивание,
      ' тип составной части( дробь, отклонение, выражение
      ' типа суммы ) )
      itemPar.s = "1 компонента 1 строка" ' Строка компоненты
      itemArr.ksAddArrayItem(-1, itemPar) ' Добавим 1-ю компоненту в массив компонент,
      ' элемент добавляется в конец массива

      ' Создаем 2-ю компоненту текста
      font.height = 20 ' Высота текста
      font.ksu = 2 ' Сужение текста
      font.color = 2000 ' Цвет
      font.bitVector = 2 ' Битовый вектор (наклон, толщина, подчеркивание,
      ' тип составной части(дробь, отклонение, выражение
      ' типа суммы))
      itemPar.s = "2 компонента 1 строка" ' Строка компоненты
      itemArr.ksAddArrayItem(-1, itemPar) ' Добавим 2-ю компоненту в массив компонент,
      ' элемент добавляется в конец массива

      ' Создаем первую строку текста
      linePar.style = 1 ' Номер стиля строки текста

      ' Создать интерфейс динамического массива строк
      lineArr = Kompas.GetDynamicArray(TEXT_LINE_ARR)

      If Not lineArr Is Nothing Then ' Интерфейс создан
        lineArr.ksAddArrayItem(-1, linePar) ' Добавим строку текста, элемент добавляется
        ' в конец массива
        itemArr.ksClearArray() ' Очистили массив компонент, чтобы использовать
        ' для создания 2-й строки текста

        ' Создаем вторую строку текста
        font.height = 30 ' Высота текста
        font.ksu = 3 ' Сужение текста
        font.color = 3000 ' Цвет
        font.bitVector = 3 ' Битовый вектор (наклон, толщина, подчеркивание,
        ' тип составной части(дробь, отклонение, выражение
        ' типа суммы))
        itemPar.s = "1 компонента 2 строка" ' Строка компоненты
        itemArr.ksAddArrayItem(-1, itemPar) ' Добавим 1-ю компоненту в массив компонент,
        ' элемент добавляется в конец массива

        ' Создаем 2-ю компоненту текста
        font.height = 40 ' Высота текста
        font.ksu = 4 ' Сужение текста
        font.color = 4000 ' Цвет
        font.bitVector = 4 ' Битовый вектор (наклон, толщина, подчеркивание,
        ' тип составной части(дробь, отклонение, выражение
        ' типа суммы))
        itemPar.s = "2 компонента 2 строка" ' Строка компоненты
        itemArr.ksAddArrayItem(-1, itemPar) ' Добавим 2-ю компоненту в массив компонент,
        ' элемент добавляется в конец массива

        ' 2-я строка текста состоит из двух компонент добавим строку текста в массив строк текста
        linePar.style = 2 ' Номер стиля строки текста
        lineArr.ksAddArrayItem(-1, linePar) ' Добавим строку текста, элемент добавляется в конец массива
        Kompas.ksMessageBoxResult() ' Проверяем результат работы нашей функции

        n = lineArr.ksGetArrayCount ' Количество элементов в массиве строки
        Kompas.ksMessage("n = " & n) ' Вывод


        ' Просмотрим массив строк текста
        For i = 0 To n - 1 ' Цикл по строкам текста
          lineArr.ksGetArrayItem(i, linePar) ' Получить значение элемента массива
          Kompas.ksMessage("i = " & i & " style = " & linePar.style) ' Вывод

          itemArr = linePar.GetTextItemArr ' Массив компонет строки текста
          If Not itemArr Is Nothing Then ' Компоненты есть
            n1 = itemArr.ksGetArrayCount ' Количество элементов в массиве компонент

            For j = 0 To n1 - 1 ' Цикл по компонентам строки текста
              itemArr.ksGetArrayItem(j, itemPar) ' Получить значение элемента массива

              font = itemPar.GetItemFont ' Шрифт
              Kompas.ksMessage("j = " & j & " h = " & font.height & " s = " & itemPar.s) ' Вывод
            Next j
          End If
        Next i

        lineArr.ksDeleteArray() ' Удалить динамический массив компонент
        itemArr.ksDeleteArray() ' Удалить динамический массив строк текста

      End If
    End If

    Kompas.ksMessageBoxResult() ' Проверяем результат работы нашей функции

  End Sub

  ' Функция для отображения массива колонок

  Sub ShowColumns(ByRef arr As Object, ByVal f1 As Boolean)
    Dim i1 As Object
    'Dim s As Object
    Dim i As Object
    Dim n As Object
    Dim par As Kompas6API5.ColumnInfoParam
    Dim columnArr As Kompas6API5.DynamicArray
    Dim fieldEnum As Kompas6API5.DynamicArray
    Dim charBuf As Kompas6API5.Char255 ' Интерфейс ksChar255 ' Интерфейс ksDynamicArray ' Интерфейс ksColumnInfoParam
    If Not arr Is Nothing Then ' Массив есть

      ' Структура параметров колонки табличного атрибута
      par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)

      If Not par Is Nothing Then ' Интерфейс создан
        par.Init() ' Инициализация

        ' Динамический массив неопределенной длины информации о колонках записи
        columnArr = par.GetColumns()

        ' Массив строк неопределенной длины для хранения перечислений
        fieldEnum = par.GetFieldEnum()

        ' Интерфейсы получены
        If (Not columnArr Is Nothing) And (Not fieldEnum Is Nothing) Then
          n = arr.ksGetArrayCount ' Количество элементов в массиве колонок

          For i = 0 To n - 1 ' Просмотрим массив колонок
            If arr.ksGetArrayItem(i, par) = 0 Then ' Получить значение элемента массива
              Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
            Else
              ' Выдадим информацию о колонке
              Kompas.ksMessage("i = " & i & " header = " & par.header & " type = " & par.type & " def = " & par.def & " flagEnum = " & par.flagEnum)

              ' Если тип данных в колонки - запись( RECORD ), то массив columns в свою очередь
              ' содержит структуры, определяющие поля этой записи.
              If par.type = RECORD_ATTR_TYPE Then ' Если структура
                ShowColumns(par.GetColumns, True)
              Else

                If par.flagEnum Then ' Выдадим массив перечислений

                  Kompas.ksMessage("массив перечислений")

                  ' Создать интерфейс строки длиной 255 символов
                  charBuf = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)

                  If Not charBuf Is Nothing Then ' Интерфейс создан

                    For i1 = 0 To fieldEnum.ksGetArrayCount() - 1 ' Просмотрим массив перечислений

                      ' Получить значение элемента массива
                      If fieldEnum.ksGetArrayItem(i1, charBuf) = 0 Then
                        Kompas.ksMessageBoxResult() ' Выдать сообщение об ошибке на экран
                      Else
                        Kompas.ksMessage(charBuf.str)
                      End If
                    Next i1
                  End If
                End If
              End If
            End If
          Next i
        End If
      End If
    End If
  End Sub

  '  Массив предназначен для создания и получения типа атрибута,
  '  который может состоять из нескольких колонок

  Sub AttrIndefiniteArray()
    '   Создадим массив из 3 колонок
    '   первая колонка описывает  int с перечисленными значениями ( 100, 200, 300 )
    '   вторая колонка - запись соответствует структуре
    '   {
    '     double ;// умолчательное значение 123456789
    '     long   ;// умолчательное значение 1000000
    '     char   ;// умолчательное значение 10
    '   }
    '   третья колонка строка символов умолчательное значение "text"

    ' Создать динамические массивы
    Dim pCol As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    pCol = Kompas.GetDynamicArray(ATTR_COLUMN_ARR) ' Динамический массив колонок
    Dim pStruct As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    pStruct = Kompas.GetDynamicArray(ATTR_COLUMN_ARR) ' Динамический массив колонок записи
    Dim pEnum As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    pEnum = Kompas.GetDynamicArray(CHAR_STR_ARR) ' Динамический массив перечисленных значений

    Dim parCol1 As Kompas6API5.ColumnInfoParam ' Интерфейс ksColumnInfoParam
    parCol1 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam) ' Структура параметров первой колонки

    ' Интерфейсы созданы
    Dim charBuf As Kompas6API5.Char255
    Dim parCol2 As Kompas6API5.ColumnInfoParam
    Dim parStruct As Kompas6API5.ColumnInfoParam
    Dim parCol3 As Kompas6API5.ColumnInfoParam ' Интерфейс ksColumnInfoParam ' Интерфейс ksChar255
    If (Not pCol Is Nothing) And (Not pStruct Is Nothing) And (Not pEnum Is Nothing) And (Not parCol1 Is Nothing) Then
      parCol1.Init() ' Первая колонка

      parCol1.header = "int" ' Заголовoк-комментарий столбца
      parCol1.type = 3 ' Тип данных в столбце - см.ниже
      parCol1.key = 0 ' Дополнительный признак, который позволит
      ' отличить две переменные с одинаковым типом
      parCol1.def = "100" ' Значение по умолчанию
      parCol1.flagEnum = 1 ' Флаг включающий режим, когда значение поля атрибута
      ' будет заполнятся из массива перечисленных значений 1 и 0 отключон
      ' флаг включающий режим, когда значение поля атрибута
      ' будет заполнятся из массива перечисленных значений 1 и 0 отключон
      parCol1.SetFieldEnum(pEnum) ' Массив неопределенной длины перечислений (строки)
      parCol1.SetColumns(Nothing) ' Массив неопределенной длины информации о колонках для записи

      ' Заполним массив перечисленных значений для первой колонки, элементы добавляется в конец массива
      ' Создать интерфейс строки длиной 255 символов
      charBuf = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)

      If Not charBuf Is Nothing Then ' Интерфейс создан
        charBuf.str = "100" ' 1-е значение
        pEnum.ksAddArrayItem(-1, charBuf) ' Добавим 1-е значение, элемент добавляется в конец массива

        charBuf.str = "200" ' 2-е значение
        pEnum.ksAddArrayItem(-1, charBuf) ' Добавим 2-е значение, элемент добавляется в конец массива

        charBuf.str = "300" ' 3-е значение
        pEnum.ksAddArrayItem(-1, charBuf) ' Добавим 3-е значение, элемент добавляется в конец массива

        pCol.ksAddArrayItem(-1, parCol1) ' Добавим первую колонку, элемент добавляется в конец массива

        ' Если тип данных в колонке - запись( RECORD ), то массив columns в свою очередь
        ' содержит структуры, определяющие поля этой записи.
        ' Структура параметров второй колонки
        parCol2 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)

        If Not parCol2 Is Nothing Then ' Интерфейс создан
          parCol2.Init() ' Вторая колонка
          parCol2.header = "struct" ' Заголовoк-комментарий столбца
          parCol2.type = 9 ' Тип данных в столбце - см.ниже
          parCol2.key = 0 ' Дополнительный признак, который позволит отличить
          ' две переменные с одинаковым типом
          parCol2.def = "\0" ' Значение по умолчанию
          parCol2.flagEnum = 0 ' Флаг включающий режим, когда значение поля атрибута будет заполнятся
          ' из массива перечисленных значений 1 и 0 отключен
          parCol2.SetFieldEnum(Nothing) ' Массив неопределенной длины перечислений (строки)
          parCol2.SetColumns(pStruct) ' Массив неопределенной длины информации о колонках для записи

          ' Структура параметров колонки табличного атрибута
          parStruct = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)

          If Not parStruct Is Nothing Then ' Интерфейс создан
            ' Заполним массив колонок для структуры
            ' Первая колонка структуры
            parStruct.header = "double" ' Заголовoк-комментарий столбца
            parStruct.type = 7 ' Тип данных в столбце - см.ниже
            parStruct.key = 0 ' Дополнительный признак, который позволит отличить две
            ' переменные с одинаковым типом
            parStruct.def = "123456789" ' Значение по умолчанию
            parStruct.flagEnum = 0 ' Флаг включающий режим, когда значение поля атрибута
            ' будет заполнятся из массива перечисленных значений 1 и 0 отключон

            parStruct.SetFieldEnum(Nothing) ' Массив неопределенной длины перечислений (строки)
            parStruct.SetColumns(Nothing) ' Массив неопределенной длины информации о колонках для записи
            ' Добавим первую колонку структуры, элемент добавляется в конец массива
            pStruct.ksAddArrayItem(-1, parStruct)

            ' Вторая колонка структуры
            parStruct.header = "long" ' Заголовoк-комментарий столбца
            parStruct.type = 5 ' Тип данных в столбце - см.ниже
            parStruct.key = 0 ' Дополнительный признак, который позволит отличить две
            ' переменные с одинаковым типом
            parStruct.def = "1000000" ' Значение по умолчанию
            parStruct.flagEnum = 0 ' Флаг включающий режим, когда значение поля атрибута
            ' будет заполнятся из массива перечисленных значений 1 и 0 отключон

            parStruct.SetFieldEnum(Nothing) ' Массив неопределенной длины перечислений (строки)
            parStruct.SetColumns(Nothing) ' Массив неопределенной длины информации о колонках для записи
            ' Добавим вторую колонку структуры, элемент добавляется в конец массива
            pStruct.ksAddArrayItem(-1, parStruct)

            ' Третья колонка структуры
            parStruct.header = "char" ' Заголовoк-комментарий столбца
            parStruct.type = 1 ' Тип данных в столбце - см.ниже
            parStruct.key = 0 ' Дополнительный признак, который позволит отличить две
            ' переменные с одинаковым типом
            parStruct.def = "10" ' Значение по умолчанию
            parStruct.flagEnum = 0 ' Флаг включающий режим, когда значение поля атрибута
            ' будет заполнятся из массива перечисленных значений 1 и 0 отключон

            parStruct.SetFieldEnum(Nothing) ' Массив неопределенной длины перечислений (строки)
            parStruct.SetColumns(Nothing) ' Массив неопределенной длины информации о колонках для записи
            ' Добавим третью колонку структуры, элемент добавляется в конец массива
            pStruct.ksAddArrayItem(-1, parStruct)

            ' Добавим вторую колонку, элемент добавляется в конец массива
            pCol.ksAddArrayItem(-1, parCol2)

            ' Структура параметров колонки табличного атрибута
            parCol3 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)
            If Not parCol3 Is Nothing Then ' Интерфейс создан
              parCol3.Init() ' Третья  колонка

              parCol3.header = "string" ' Заголовoк-комментарий столбца
              parCol3.type = 8 ' Тип данных в столбце - см.ниже
              parCol3.key = 0 ' Дополнительный признак, который позволит отличить две
              ' переменные с одинаковым типом
              parCol3.def = "text" ' Значение по умолчанию
              parCol3.flagEnum = 0 ' Флаг включающий режим, когда значение поля атрибута
              ' будет заполнятся из массива перечисленных значений 1 и 0 отключон
              parStruct.SetFieldEnum(Nothing) ' Массив неопределенной длины перечислений (строки)
              parStruct.SetColumns(Nothing) ' Массив неопределенной длины информации о колонках для записи

              ' Добавим третью колонку, элемент добавляется в конец массива
              pCol.ksAddArrayItem(-1, parCol3)

              ShowColumns(pCol, False) ' Просмотрим массив колонок

              Kompas.ksMessageBoxResult() ' Результат выполнения

              ' Поменяем колонки местами 2->1, 1->3, 3->2 ( изменим параметры )
              pCol.ksSetArrayItem(0, parCol2)
              pCol.ksSetArrayItem(2, parCol1)
              pCol.ksSetArrayItem(1, parCol3)

              ShowColumns(pCol, False) ' Просмотрим массив колонок
            End If
          End If
        End If
      End If

      Kompas.ksMessageBoxResult() ' Результат выполнения

      ' Удалить динамические массивы
      pCol.ksDeleteArray() ' Динамический массив колонок
      pStruct.ksDeleteArray() ' Динамический массив колонок записи
      pEnum.ksDeleteArray() ' Динамический массив перечисленных значений

    End If
  End Sub

  ' Массив полилиний это массив массивов математических точек

  Sub PolyLineArray()
    Dim pPoly As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Массив полилиний - массивы математических точек
    pPoly = Kompas.GetDynamicArray(POLYLINE_ARR)

    Dim par As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    ' Структура параметров математической точки
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

    Dim arr As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Массив для хранения математических точек
    arr = Kompas.GetDynamicArray(POINT_ARR)

    ' Интерфейсы созданы
    Dim count As Short
    Dim i As Short
    Dim count1 As Short
    Dim j As Short
    Dim arr2 As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    If (Not pPoly Is Nothing) And (Not par Is Nothing) And (Not arr Is Nothing) Then
      par.x = 10 ' Наполнить массив математических точек
      par.y = 10
      arr.ksAddArrayItem(-1, par) ' Добавим 1-ю точку, элемент добавляется в конец массива

      par.x = 100
      par.y = 100
      arr.ksAddArrayItem(-1, par) ' Добавим 2-ю точку, элемент добавляется в конец массива

      par.x = 1000
      par.y = 1000
      arr.ksAddArrayItem(-1, par) ' Добавим 3-ю точку, элемент добавляется в конец массива

      ' Добавим 1-й массив математических точек в массив полилиний, элемент добавляется в конец массива
      pPoly.ksAddArrayItem(-1, arr)

      ' Очистили массив математических точек, чтобы использовать для создания 2-й полилинии
      arr.ksClearArray()

      par.x = 20 ' Наполнить массив математических точек
      par.y = 20
      arr.ksAddArrayItem(-1, par) ' Добавим 1-ю точку, элемент добавляется в конец массива

      par.x = 200
      par.y = 200
      arr.ksAddArrayItem(-1, par) ' Добавим 2-ю точку, элемент добавляется в конец массива

      par.x = 2000
      par.y = 2000
      arr.ksAddArrayItem(-1, par) ' Добавим 3-ю точку, элемент добавляется в конец массива

      ' Добавим 2-й массив математических точек в массив полилиний, элемент добавляется в конец массива
      pPoly.ksAddArrayItem(-1, arr)

      ' Очистили массив математических точек, чтобы использовать для создания 3-й полилинии
      arr.ksClearArray()

      par.x = 30 ' Наполнить массив математических точек
      par.y = 30
      arr.ksAddArrayItem(-1, par) ' Добавим 1-ю точку, элемент добавляется в конец массива

      par.x = 300
      par.y = 300
      arr.ksAddArrayItem(-1, par) ' Добавим 2-ю точку, элемент добавляется в конец массива

      par.x = 3000
      par.y = 3000
      arr.ksAddArrayItem(-1, par) ' Добавим 3-ю точку, элемент добавляется в конец массива

      ' Добавим 3-й массив математических точек в массив полилиний, элемент добавляется в конец массива
      pPoly.ksAddArrayItem(-1, arr)

      count = pPoly.ksGetArrayCount() ' Количество элементов в массиве полилиний
      Kompas.ksMessage("count = " & count) ' Вывести количество элементов в массиве полилиний

      ' Просмотрим массив полилиний
      ' Цикл по полилиниям - массивы математических точек
      For i = 0 To count - 1
        ' Получить значение элемента массива
        pPoly.ksGetArrayItem(i, arr)

        ' Количество элементов в массиве математических точек
        count1 = arr.ksGetArrayCount

        ' Цикл по полилинии - массиву математических точек
        For j = 0 To count1 - 1
          ' Получить значение элемента массива
          arr.ksGetArrayItem(j, par)
          Kompas.ksMessage("i = " & i & " j = " & j & " x = " & par.x & " y = " & par.y)
        Next j
      Next i

      ' Заменим у второго элемента массива полилиний( массива математических точек ) первый и второй элемент
      par.x = 50
      par.y = 50
      arr.ksSetArrayItem(1, par) ' Второй элемент

      par.x = 500
      par.y = 500
      arr.ksSetArrayItem(0, par) ' Первый элемент

      ' Установить значение элемента динамического массива математических точек
      pPoly.ksSetArrayItem(1, arr)

      count = pPoly.ksGetArrayCount() ' Количество элементов в массиве полилиний

      ' создадим массив точек
      ' Массив для хранения математических точек
      arr2 = Kompas.GetDynamicArray(POINT_ARR)

      If Not arr2 Is Nothing Then ' Интерфейс создан

        ' Просмотрим массив полилиний
        ' Цикл по полилиниям - массивы математических точек
        For i = 0 To count - 1
          pPoly.ksGetArrayItem(i, arr2) ' Получить значение элемента массива

          ' Цикл по полилинии - массиву математических точек
          For j = 0 To arr2.ksGetArrayCount() - 1 ' Количество элементов в массиве математических точек
            arr2.ksGetArrayItem(j, par) ' Получить значение элемента массива
            Kompas.ksMessage("j = " & j & " x = " & par.x & " y = " & par.y)
          Next j
        Next i

        arr2.ksDeleteArray() ' Массив для хранения математических точек
      End If

      Kompas.ksMessageBoxResult() ' Результат выполнения

      ' Удалить динамические массивы
      arr.ksDeleteArray() ' Массив для хранения математических точек
      pPoly.ksDeleteArray() ' Массив полилиний - массивы математических точек
    End If
  End Sub

  ' Массив неопределенной длины габаритных прямоугольников( Интерфейс ksRectParam )

  Sub RectArray()
    Dim i As Object
    Dim arr As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    arr = Kompas.GetDynamicArray(RECT_ARR) ' Создать динамический массив габаритных прямоугольников

    Dim par As Kompas6API5.RectParam ' Интерфейс ksRectParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RectParam) ' Структура параметров прямоугольника по диагональным точкам

    Dim mathPar As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    ' Структура параметров математической точки
    mathPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

    ' Интерфейсы созданы
    Dim n As Short
    Dim mathPar2 As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    If (Not arr Is Nothing) And (Not par Is Nothing) And (Not mathPar Is Nothing) Then
      ' Наполнить динамический массив габаритных прямоугольников
      mathPar.x = 10 ' Параметры правой верхней точки прямоугольника
      mathPar.y = 10
      par.SetpTop(mathPar)

      mathPar.x = 20 ' Параметры левой нижней точки прямоугольника
      mathPar.y = -10
      par.SetpBot(mathPar)

      arr.ksAddArrayItem(-1, par) ' Добавим 1-й прямоугольник, элемент добавляется в конец массива

      mathPar.x = 20 ' Параметры правой верхней точки прямоугольника
      mathPar.y = 50
      par.SetpTop(mathPar)

      mathPar.x = 50 ' Параметры левой нижней точки прямоугольника
      mathPar.y = 10
      par.SetpBot(mathPar)

      arr.ksAddArrayItem(-1, par) ' Добавим 2-й прямоугольник, элемент добавляется в конец массива

      mathPar.x = 20 ' Параметры правой верхней точки прямоугольника
      mathPar.y = 150
      par.SetpTop(mathPar)

      mathPar.x = 50 ' Параметры левой нижней точки прямоугольника
      mathPar.y = 110
      par.SetpBot(mathPar)

      arr.ksAddArrayItem(-1, par) ' Добавим 3-й прямоугольник, элемент добавляется в конец массива

      n = arr.ksGetArrayCount() ' Количество элементов в массиве габаритных прямоугольников
      Kompas.ksMessage("n = " & n)

      ' Структура параметров математической точки
      mathPar2 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

      If Not mathPar2 Is Nothing Then ' Интерфейс создан

        For i = 0 To n - 1 ' Просмотрим массив габаритных прямоугольников
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          arr.ksGetArrayItem(i, par) ' Получить значение элемента массива
          mathPar = par.GetpTop() ' Параметры правой верхней точки прямоугольника
          mathPar2 = par.GetpBot() ' Параметры левой нижней точки прямоугольника
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage("i = " & i & " x1 = " & mathPar.x & " y1 = " & mathPar.y & " x1 = " & mathPar2.x & " y1 = " & mathPar2.y)
        Next i

        ' Редактируем массив габаритных прямоугольников
        mathPar.x = -20 ' Параметры правой верхней точки прямоугольника
        mathPar.y = -50
        par.SetpTop(mathPar)

        mathPar.x = 20 ' Параметры левой нижней точки прямоугольника
        mathPar.y = -10
        par.SetpBot(mathPar)
        ' Установить значение 1-го элемента динамического массива габаритных прямоугольников
        arr.ksSetArrayItem(0, par)

        mathPar.x = 0 ' Параметры правой верхней точки прямоугольника
        mathPar.y = 0
        par.SetpTop(mathPar)

        mathPar.x = 10 ' Параметры левой нижней точки прямоугольника
        mathPar.y = -20
        par.SetpBot(mathPar)
        ' Установить значение 2-го элемента динамического массива габаритных прямоугольников
        arr.ksSetArrayItem(1, par)

        mathPar.x = 5 ' Параметры правой верхней точки прямоугольника
        mathPar.y = 5
        par.SetpTop(mathPar)

        mathPar.x = 25 ' Параметры левой нижней точки прямоугольника
        mathPar.y = 0
        par.SetpBot(mathPar)
        arr.ksAddArrayItem(-1, par) ' Добавим 4-й прямоугольник, элемент добавляется в конец массива

        n = arr.ksGetArrayCount() ' Количество элементов в массиве габаритных прямоугольников

        For i = 0 To n - 1 ' Просмотрим массив габаритных прямоугольников
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          arr.ksGetArrayItem(i, par) ' Получить значение элемента массива
          mathPar = par.GetpTop() ' Параметры правой верхней точки прямоугольника
          mathPar2 = par.GetpBot() ' Параметры левой нижней точки прямоугольника
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage("i = " & i & " x1 = " & mathPar.x & " y1 = " & mathPar.y & " x1 = " & mathPar2.x & " y1 = " & mathPar2.y)
        Next i

        Kompas.ksMessageBoxResult() ' Результат выполнения

        arr.ksDeleteArray() ' Удалить динамический массив габаритных прямоугольников
      End If
    End If
  End Sub

  ' Головная функция библиотеки - вызывается при выборе пункта меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Kompas6API5.Application)
    Kompas = kompas_ ' Интерфейс приложения КОМПАС

    Dim doc As Kompas6API5.Document2D ' Интерфейс ksDocument2D
    doc = Kompas.ActiveDocument2D ' Возьмем интерфейс текущего 2D документа

    Select Case command_Renamed
      Case 1 ' Массив строк
        StrIndefiniteArray(doc)

      Case 2 ' Массив математических точек
        PointIndefiniteArray(doc)

      Case 3 ' Массив строк объекта "текст"
        TextIndefiniteArray(doc)

      Case 4 ' Массив колонок типа атрибута
        AttrIndefiniteArray()

      Case 5 ' Массив полилиний
        PolyLineArray()

      Case 6 ' Массив габаритных прямоугольников
        RectArray()
    End Select
  End Sub

  ' Сформировать меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 3 '"ENDMENU"'
    ExternalMenuItem = ""
    command_Renamed = -1

    Select Case number
      Case 1 ' Команда 1 - массив простых строк
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массив простых строк"
        command_Renamed = 1
      Case 2 ' Команда 2 - массив точек
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массив точек"
        command_Renamed = 2
      Case 3 ' Команда 3 - массив строк текста
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массив строк текста"
        command_Renamed = 3
      Case 4 ' Команда 4 - массив колонок типа атрибута
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массив колонок типа атрибута"
        command_Renamed = 4

      Case 5 ' Команда 5 - массив полилиний
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массив полилиний"
        command_Renamed = 5
      Case 6 ' Команда 6 - массив габ. прямоугольников
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массив габ. прямоугольников"
        command_Renamed = 6
      Case 7 ' Завершение формирования меню
        itemType = 3 '"ENDMENU"'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  <ComRegisterFunctionAttribute()> _
  Friend Shared Sub RegisterKompasLib(ByVal typeToRegister As Type)
    Try
      Dim regKey As RegistryKey
      regKey = Registry.LocalMachine
      Dim keyName As String
      keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
      regKey = regKey.OpenSubKey(keyName, True)
      regKey.CreateSubKey("Kompas_Library")
      regKey = regKey.OpenSubKey("InprocServer32", True)
      regKey.SetValue(Nothing, System.Environment.GetFolderPath(Environment.SpecialFolder.System) + "\mscoree.dll")
      regKey.Close()

    Catch e As Exception
      MsgBox(e.Message, MsgBoxStyle.OkOnly)
    End Try

  End Sub

  <ComUnregisterFunctionAttribute()> _
  Friend Shared Sub UnregisterKompasLib(ByVal typeToRegister As Type)
    Dim regKey As RegistryKey
    regKey = Registry.LocalMachine
    Dim keyName As String
    keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
    regKey = regKey.OpenSubKey(keyName, True)
    regKey.DeleteSubKey("Kompas_Library")
    regKey.Close()
  End Sub
End Class