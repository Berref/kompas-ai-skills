Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step3a")> _
Public Class Step3a
  ' step3a - Объекты - a

  ' 1.  Контур                            - WorkContour
  ' 2.  Технические требования            - TDemWork
  ' 3.  Стрелка вида                      - DrawViewPointer
  ' 4.  Работа со штампом                 - WorkStamp
  ' 5.  Таблица                           - TableWork
  ' 6.  Эквидистанта                      - DrawEquidistant
  ' 7.  Эллипс                            - DrawEllipse
  ' 8.  Полилиния                         - DrawPolyline
  ' 9.  Nurbs                             - DrawNurbs
  ' 10. Допуск формы                      - WorkTolerance
  ' 11. Одинаковая шероховатость          - DrawSpecRough
  ' 12. Вставка фрагмента внешней ссылкой - DrawInsFragment1
  ' 13. Вставка локального фрагмента      - DrawInsFragment2


  Public Kompas As Kompas6API5.Application ' Интерфейс KompasObject

  ' Построить контур

  Sub WorkContour(ByRef doc As Kompas6API5.Document2D)
    ' Задание контура, style - стиль линии ( 1 - основная, 2 - тонкая,
    ' 3 - осевая, 4 - штриховая,  5 - волнистая, 6 - утолщенная,
    ' 7 - штрихпунктирная с двумя точками,  8 - осевая основная,
    ' 9 - штриховая основная, 10 - осевая толстая,
    ' 11 - тонкая, включаемая в штриховку )
    Dim contour As Integer
    Dim g As Integer
    If doc.ksContour(1) Then
      doc.ksLineSeg(20, 30, 50, 30, 1) ' Отрезок
      doc.ksArcByPoint(50, 20, 10, 50, 30, 50, 10, -1, 1) ' Дуга по двум точкам

      doc.ksContour(2) ' Вложенный контур
      doc.ksLineSeg(50, 10, 20, 10, 1) ' Отрезок
      doc.ksArcByPoint(20, 20, 10, 20, 10, 20, 30, -1, 1) ' Дуга по двум точкам
      doc.ksEndObj() ' Функция EndObj возвращает указатель на созданный объект контур

      contour = doc.ksEndObj ' Функция EndObj возвращает указатель на созданный объект контур

      doc.ksLightObj(contour, 1) ' Подсветить контур
      Kompas.ksMessage("контур")
      doc.ksLightObj(contour, 1) ' Снять выделение контура

      ' Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
      g = doc.ksNewGroup(0)
      doc.ksEndGroup() ' Завершить создание группы объектов

      doc.ksAddObjGroup(g, contour) ' Добавить новый объект в группу
      doc.ksMoveObj(g, 10, 10) ' Сдвинуть группу на 10 по оси OX, на 10 по оси OY
      Kompas.ksMessage("сдвинули группу")
    End If
  End Sub

  ' Заполнение технических требований

  Sub TDemWork(ByRef doc As Kompas6API5.Document2D)
    ' Поместим техтребования в двух габаритных окнах
    Dim pGab As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    pGab = Kompas.GetDynamicArray(RECT_ARR) ' Динамический массив габаритных прямоугольников

    Dim par As Kompas6API5.RectParam ' Интерфейс ksRectParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RectParam) ' Структура параметров прямоугольника по диагональным точкам

    Dim pBot As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    pBot = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam) ' Интерфейс параметров математической точки

    Dim pTop As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    pTop = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam) ' Интерфейс параметров математической точки

    ' Интерфейсы созданы
    Dim itemParam As Kompas6API5.TextItemParam
    Dim itemFont As Kompas6API5.TextItemFont ' Интерфейс ksTextItemFont ' Интерфейс ksTextItemParam
    If Not pGab Is Nothing And Not par Is Nothing And Not pBot Is Nothing And Not pTop Is Nothing Then
      pBot.Init() ' Инициализация
      pTop.Init() ' Инициализация

      pTop.x = 415 ' Параметры правой верхней точки прямоугольника
      pTop.y = 80
      par.SetpTop(pTop) ' Верхняя точка прямоугольника
      pBot.x = 230 ' Параметры левой нижней точки прямоугольника
      pBot.y = 65
      par.SetpBot(pBot) ' Нижняя точка прямоугольника

      pGab.ksAddArrayItem(-1, par) ' Добавим прямоугольник в массив, элемент добавляется в конец массива

      pTop.x = 230 ' Параметры правой верхней точки прямоугольника
      pTop.y = 60
      par.SetpTop(pTop) ' Верхняя точка прямоугольника
      pBot.x = 45 ' Параметры левой нижней точки прямоугольника
      pBot.y = 15
      par.SetpBot(pBot) ' Нижняя точка прямоугольника

      pGab.ksAddArrayItem(-1, par) ' Добавим прямоугольник в массив, элемент добавляется в конец массива

      ' Параметры метода ksOpenTechnicalDemand
      ' 1. Динамический массив габаритных прямоугольников,
      ' 2. 0 - технические требования размещаются на одной странице автоматически
      If doc.ksOpenTechnicalDemand(pGab, 0) Then ' Открыть технические требования
        ' Интерфейс параметров компоненты строки текста
        itemParam = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)

        If Not itemParam Is Nothing Then ' Интерфейс создан
          itemParam.Init() ' Инициализация

          itemFont = itemParam.GetItemFont ' Интерфейс параметров шрифта компоненты строки текста

          If Not itemFont Is Nothing Then ' Интерфейс создан
            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "1111111" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в технические требования

            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "2222222" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в технические требования

            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "3333333" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в технические требования

            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "4444444" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в технические требования

            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "5555555" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в технические требования

            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "6666666" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в технические требования

            'UPGRADE_NOTE: Object itemFont may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            itemFont = Nothing
          End If

          'UPGRADE_NOTE: Object itemParam may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          itemParam = Nothing
        End If

        doc.ksCloseTechnicalDemand() ' Закрыть технические требования
      End If

      'UPGRADE_NOTE: Object pGab may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      pGab = Nothing
      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object pBot may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      pBot = Nothing
      'UPGRADE_NOTE: Object pTop may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      pTop = Nothing
    End If
  End Sub

  ' Создание таблицы

  Sub TableWork(ByRef doc As Kompas6API5.Document2D)
    doc.ksTable() ' Определение таблицы, возвращает указатель на графический объект таблица
    doc.ksLineSeg(50, 50, 90, 50, 1) ' Разлиновка таблицы
    doc.ksLineSeg(50, 40, 90, 40, 1)
    doc.ksLineSeg(50, 30, 90, 30, 1)
    doc.ksLineSeg(50, 50, 50, 30, 1)
    doc.ksLineSeg(70, 50, 70, 30, 1)
    doc.ksLineSeg(90, 50, 90, 30, 1)

    doc.ksText(52, 48, 0, 5, 1, 0, "1") ' Тексты в ячейках таблицы
    doc.ksText(72, 48, 0, 5, 1, 0, "2")
    doc.ksText(52, 38, 0, 5, 1, 0, "3")
    doc.ksText(72, 38, 0, 5, 1, 0, "4")
    doc.ksEndObj() ' Описание таблицы заканчивается функцией EndObj
  End Sub

  ' Создание стрелки вида

  Sub DrawViewPointer(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.ViewPointerParam ' Интерфейс ksViewPointerParam
    ' Интерфейс параметров стрелки направления взгляда
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewPointerParam)

    Dim p As Integer
    If Not par Is Nothing Then ' Интерфейс создан
      par.Init() ' Инициализация

      par.x1 = 55 ' Координаты вершины (острия) стрелки
      par.y1 = 50
      par.x2 = 40 ' Координаты конечной точки стрелки
      par.y2 = 50
      par.xt = 40 ' Координаты текста
      par.yt = 52
      par.type = 0 ' Способ задания надписи на линии ( 0 - текст в виде строки,
      ' 1 - динамический массив компонент текста )
      par.str = "A" ' надпись

      p = doc.ksViewPointer(par) ' Создание стрелки направления взгляда

      If doc.ksExistObj(p) Then ' Если создали стрелку направления взгляда
        doc.ksLightObj(p, 1) ' Подсветить стрелку
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksMessage("Снять выделение стрелки")
        doc.ksLightObj(p, 0) ' Снять выделение стрелки
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Заполнение основной надписи

  Sub WorkStamp(ByRef doc As Kompas6API5.Document2D)
    Dim stamp As Kompas6API5.Stamp ' Интерфейс ksStamp
    stamp = doc.GetStamp ' Интерфейс основной надписи

    Dim itemParam As Kompas6API5.TextItemParam
    Dim itemFont As Kompas6API5.TextItemFont ' Интерфейс ksTextItemFont ' Интерфейс ksTextItemParam
    If Not stamp Is Nothing Then ' Интерфейс создан
      If stamp.ksOpenStamp Then ' Открыть штамп чертежа/текстового документа
        stamp.ksColumnNumber(2) ' Определить номер графы штампа, определяет графу с номером как текущую

        ' Интерфейс параметров компоненты строки текста
        itemParam = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)

        If Not itemParam Is Nothing Then ' Интерфейс создан
          itemParam.Init() ' Инициализация

          itemFont = itemParam.GetItemFont ' Интерфейс параметров шрифта компоненты строки текста

          If Not itemFont Is Nothing Then ' Интерфейс создан
            itemFont.Init() ' Инициализация
            itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
            itemParam.s = "1111111" ' Текст компоненты строки текста
            doc.ksTextLine(itemParam) ' Добавить строку в ячейку основной надписи

            'UPGRADE_NOTE: Object itemFont may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            itemFont = Nothing
          End If

          'UPGRADE_NOTE: Object itemParam may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          itemParam = Nothing
        End If

        stamp.ksCloseStamp() ' Закрыть штамп чертежа/текстового документа
      End If

      'UPGRADE_NOTE: Object stamp may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      stamp = Nothing
    End If
  End Sub

  ' Допуск формы

  Sub WorkTolerance(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.ToleranceParam ' Интерфейс ksToleranceParam
    ' Интерфейс параметров обозначения допуска формы и расположения поверхностей
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ToleranceParam)

    Dim parPoint As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    parPoint = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam) ' Интерфейс параметров математической точки

    Dim branArr As Kompas6API5.DynamicArray
    Dim tolBran As Kompas6API5.ToleranceBranch
    Dim arr As Kompas6API5.DynamicArray
    Dim itemParam As Kompas6API5.TextItemParam
    Dim itemFont As Kompas6API5.TextItemFont
    Dim p As Integer ' Интерфейс ksTextItemFont ' Интерфейс ksTextItemParam ' Интерфейс ksDynamicArray ' Интерфейс ksToleranceBranch
    If Not par Is Nothing And Not parPoint Is Nothing Then ' Интерфейсы созданы
      par.Init() ' Инициализация
      parPoint.Init() ' Инициализация

      branArr = par.GetBranchArr ' Получить указатель на интерфейс динамического
      ' массива опор допуска формы
      ' Интерфейс параметров "опоры" допуска формы
      tolBran = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ToleranceBranch)

      If Not tolBran Is Nothing And Not branArr Is Nothing Then ' Интерфейсы созданы
        tolBran.Init() ' Инициализация

        arr = tolBran.GetpMathPoint ' Получить интерфейс динамического массив точек "опоры"

        If Not arr Is Nothing Then ' Интерфейс получен

          ' Заполняем параметры 1-ой опоры
          parPoint.x = 40 ' Координаты точки опоры
          parPoint.y = 10
          arr.ksAddArrayItem(-1, parPoint) ' Добавим точку опоры в массив, элемент добавляется в конец массива
          tolBran.arrowType = 2 ' Тип опоры ( 0 - нет опоры, 1 - треугольник, 2 - стрелка )
          tolBran.tCorner = 1 ' Число от 1 до 8, определяющее точку выхода "опоры" из таблицы
          branArr.ksAddArrayItem(-1, tolBran) ' Добавить параметры опоры в массив

          ' Заполняем параметры 2-ой опоры
          arr.ksClearArray() ' Очистить массив
          parPoint.x = 100 ' Координаты первой точки опоры
          parPoint.y = 50
          arr.ksAddArrayItem(-1, parPoint) ' Добавим 1-ю точку опоры в массив, элемент добавляется в конец массива
          parPoint.x = 100 ' Координаты второй точки опоры
          parPoint.y = 10
          arr.ksAddArrayItem(-1, parPoint) ' Добавим 2-ю точку опоры в массив, элемент добавляется в конец массива
          tolBran.arrowType = 1 ' Тип опоры ( 0 - нет опоры, 1 - треугольник, 2 - стрелка )
          tolBran.tCorner = 5 ' Число от 1 до 8, определяющее точку выхода "опоры" из таблицы
          branArr.ksAddArrayItem(-1, tolBran) ' Добавить параметры опоры в массив

          par.x = 40 ' Координаты базовой точки
          par.y = 40
          par.type = 0 ' Ориентация таблицы допуска ( 0 - горизонтально, 1 - вертикально )

          ' Создание обозначения допуска формы, состоящей из таблицы ( в общем случае 10х10 ) и двух опор
          If doc.ksTolerance(par) Then

            ' Интерфейс параметров компоненты строки текста
            itemParam = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)

            If Not itemParam Is Nothing Then ' Интерфейс создан
              itemParam.Init() ' Инициализация

              itemFont = itemParam.GetItemFont ' Интерфейс параметров шрифта компоненты строки текста

              If Not itemFont Is Nothing Then ' Интерфейс создан
                itemFont.Init() ' Инициализация

                doc.ksColumnNumber(1) ' Определить номер графы штампа ( 1-я графа )

                ' Задание подстроки графы штампа
                itemFont.SetBitVectorValue(SPECIAL_SYMBOL, True) ' Спецзнак
                itemParam.type = SPECIAL ' Спецзнак
                itemParam.iSNumb = 26 ' Номер спецзнака
                doc.ksTextLine(itemParam) ' Добавить подстроку

                itemParam.Init() ' Инициализация
                doc.ksColumnNumber(2) ' 2-я графа
                itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
                itemParam.s = "2222" ' Текст компоненты строки текста
                doc.ksTextLine(itemParam) ' Добавить подстроку

                doc.ksColumnNumber(3) ' 3-я графа
                itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
                itemParam.s = "2222" ' Текст компоненты строки текста
                doc.ksTextLine(itemParam) ' Добавить подстроку

                itemParam.Init() ' Инициализация
                doc.ksColumnNumber(11) ' 11-я графа
                itemFont.SetBitVectorValue(SPECIAL_SYMBOL, True) ' Спецзнак
                itemParam.type = SPECIAL ' Спецзнак
                itemParam.iSNumb = 23 ' Номер спецзнака
                doc.ksTextLine(itemParam) ' Добавить подстроку

                itemParam.Init() ' Инициализация
                doc.ksColumnNumber(12) ' 12-я графа
                itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
                itemParam.s = "444" ' Текст компоненты строки текста
                doc.ksTextLine(itemParam) ' Добавить подстроку

                doc.ksColumnNumber(13) ' 13-я графа
                itemFont.SetBitVectorValue(NEW_LINE, True) ' Новая строка
                itemParam.s = "555" ' Текст компоненты строки текста
                doc.ksTextLine(itemParam) ' Добавить подстроку

                'UPGRADE_NOTE: Object itemFont may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
                itemFont = Nothing
              End If

              'UPGRADE_NOTE: Object itemParam may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              itemParam = Nothing
            End If
          End If

          p = doc.ksEndObj ' Функция EndObj возвращает указатель на созданный объект допуска формы

          doc.ksLightObj(p, 1) ' Подсветить допуск формы

          arr.ksDeleteArray() ' Удалить динамический массив точек
          branArr.ksDeleteArray() ' Удалить динамический массив опор

          'UPGRADE_NOTE: Object tolBran may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          tolBran = Nothing
          'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          arr = Nothing
        End If
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object parPoint may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      parPoint = Nothing
    End If
  End Sub

  ' Создать эллипс

  Sub DrawEllipse(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.EllipseParam ' Интерфейс ksEllipseParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_EllipseParam) ' Интерфейс параметров эллипса

    Dim p As Integer
    If Not par Is Nothing Then ' Интерфейс создан
      par.Init() ' Инициализация

      par.xc = 50 ' Координаты центра эллипса
      par.yc = 40
      par.A = 20 ' Длина полуосей эллипса
      par.B = 10
      par.style = 1 ' Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая,
      ' 5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками,
      ' 8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
      ' 11 - тонкая, включаемая в штриховку )
      p = doc.ksEllipse(par) ' Создание эллипса

      doc.ksLightObj(p, 1) ' Подсветить эллипс
      Kompas.ksMessage("эллипс")
      doc.ksLightObj(p, 0) ' Снять выделение эллипса

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Построить эквидистанту

  Sub DrawEquidistant(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.EquidistantParam ' Интерфейс ksEquidistantParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_EquidParam) ' Интерфейс параметров эквидистанты

    Dim info As Kompas6API5.RequestInfo ' Интерфейс ksRequestInfo
    info = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo) ' Интерфейс параметров запроса к системе

    Dim x As Double
    Dim y As Double
    Dim j As Short
    Dim p1 As Integer ' Координаты точки ввода
    If Not par Is Nothing And Not info Is Nothing Then ' Интерфейсы созданы
      par.side = 2 ' Признак, с какой стороны строить эквидистанту
      ' 0-слева по направлению, 1-справа по направлению, 2-с двух сторон
      par.cutMode = 0 ' Тип обхода углов контура 0-обход срезом, 1- обход дугой
      par.degState = 0 ' Флаг разрешения вырожденных сегментов эквидистанты
      ' 0-вырожденные сегменты запрещены,
      ' 1-вырожденные сегменты разрешены
      par.radRight = 5 ' Радиус эквидистанты
      par.radLeft = 3 ' Радиус эквидистанты
      par.style = 1 ' Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая,
      ' 5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками,
      ' 8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
      ' 11 - тонкая, включаемая в штриховку )

      info.commandsString = "Укажите объект" ' Строка подсказки


      ' Найдем объект
      Do
        j = doc.ksCursor(info, x, y, Nothing) ' Интерактивный ввод точки или команды

        If Not j = 0 Then
          par.geoObj = doc.ksFindObj(x, y, 1000000.0#) ' Найти ближайший к заданной точке объект вида
          ' 1000000 - Размер стороны квадрата-ловушки с центром в точке x,y

          If doc.ksExistObj(par.geoObj) Then ' Проверить существование объекта
            p1 = doc.ksEquidistant(par) ' Создание эквидистанты

            If Not p1 = 0 Then
              doc.ksLightObj(p1, 1) ' Подсветить эквидистанту
              Kompas.ksMessage("эквидистанта")
              doc.ksLightObj(p1, 0) ' Снять выделение эквидистанты
            Else
              Kompas.ksMessageBoxResult() ' Результат выполнения
            End If
          Else
            Kompas.ksError("объект не найден")
          End If
        End If
      Loop While (j)

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      info = Nothing
    End If
  End Sub

  ' Создание полилинии

  Sub DrawPolyline(ByRef doc As Kompas6API5.Document2D)
    ' Пример создания полилинии одной функцией
    Dim par As Kompas6API5.PolylineParam ' Интерфейс ksPolylineParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PolylineParam) ' Интерфейс параметров ломаной линии

    Dim pr As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    pr = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam) ' Интерфейс параметров математической точки

    Dim arr As Kompas6API5.DynamicArray
    Dim p As Integer ' Интерфейс ksDynamicArray
    If Not par Is Nothing And Not pr Is Nothing Then ' Интерфейсы созданы
      par.Init() ' Инициализация
      pr.Init() ' Инициализация

      arr = par.GetpMathPoint ' Получить интерфейс динамического массив математических точек

      If Not arr Is Nothing Then ' Интерфейс получен
        pr.x = 10 ' 1-я точка
        pr.y = 10
        arr.ksAddArrayItem(-1, pr) ' Добавим точку в конец массива
        pr.x = 20 ' 2-я точка
        pr.y = 20
        arr.ksAddArrayItem(-1, pr) ' Добавим точку в конец массива
        pr.x = 30 ' 3-я точка
        pr.y = 10
        arr.ksAddArrayItem(-1, pr) ' Добавим точку в конец массива
        pr.x = 40 ' 4-я точка
        pr.y = 20
        arr.ksAddArrayItem(-1, pr) ' Добавим точку в конец массива

        par.style = 2 ' Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая,
        ' 5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками,
        ' 8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
        ' 11 - тонкая, включаемая в штриховку )

        p = doc.ksPolylineByParam(par) ' Создание ломаной

        doc.ksLightObj(p, 1) ' Подсветить полилинию
        Kompas.ksMessage("Полилиния")
        doc.ksLightObj(p, 0) ' Снять выделение полилинии

        arr.ksDeleteArray() ' Удалить массив точек

        'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr = Nothing
      End If

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
      'UPGRADE_NOTE: Object pr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      pr = Nothing
    End If
  End Sub

  ' Создать  Nurbs - сплайн

  Sub DrawNurbs(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.NurbsPointParam ' Интерфейс ksNurbsPointParam
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_NurbsPointParam) ' Интерфейс параметров точки кривой NURBS

    Dim p As Integer
    If Not par Is Nothing Then ' Интерфейс получен
      par.Init() ' Инициализация

      ' Построить Nurbs сплайн  как составной объект
      doc.ksNurbs(3, 0, 1)
      ' Точки входящие в сплайн
      par.x = 0 ' Координаты 1-ой точки
      par.y = 0
      par.weight = 1 ' Вес 1-ой точки (должен быть больше нуля)
      doc.ksNurbsPoint(par) ' Добавить точку в сплайн
      par.x = 20 ' Координаты 2-ой точки
      par.y = 20
      par.weight = 1 ' Вес 2-ой точки (должен быть больше нуля)
      doc.ksNurbsPoint(par) ' Добавить точку в сплайн
      par.x = 50 ' Координаты 3-ой точки
      par.y = 10
      par.weight = 1 ' Вес 3-ой точки (должен быть больше нуля)
      doc.ksNurbsPoint(par) ' Добавить точку в сплайн
      par.x = 70 ' Координаты 4-ой точки
      par.y = 20
      par.weight = 1 ' Вес 4-ой точки (должен быть больше нуля)
      doc.ksNurbsPoint(par) ' Добавить точку в сплайн
      par.x = 100 ' Координаты 5-ой точки
      par.y = 0
      par.weight = 1 ' Вес 5-ой точки (должен быть больше нуля)
      doc.ksNurbsPoint(par) ' Добавить точку в сплайн
      par.x = 50 ' Координаты 6-ой точки
      par.y = -50
      par.weight = 1 ' Вес 6-ой точки (должен быть больше нуля)
      doc.ksNurbsPoint(par) ' Добавить точку в сплайн
      p = doc.ksEndObj ' Функция EndObj возвращает указатель на созданный объект сплайн

      doc.ksLightObj(p, 1) ' Подсветить сплайн
      Kompas.ksMessage("NURBS")
      doc.ksLightObj(p, 0) ' Снять выделение сплайна

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Вставка внешнего фрагмента

  Sub DrawInsFragment1(ByRef doc As Kompas6API5.Document2D)
    Dim frg As Kompas6API5.Fragment ' Интерфейс ksFragment
    frg = doc.GetFragment ' Интерфейс фрагмента

    Dim pDefFrg As Integer
    Dim par As Kompas6API5.PlacementParam
    Dim p As Integer ' Интерфейс ksPlacementParam
    If Not frg Is Nothing Then ' Интерфейс получен
      ' Определить данные для вставки фрагмента
      pDefFrg = frg.ksFragmentDefinition("c:\1.frw", "frw1", 1)

      If Not pDefFrg = 0 Then
        par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PlacementParam) ' Параметры привязки

        If Not par Is Nothing Then ' Интерфейс создан
          par.angle = 45 ' Угол поворота в системе координат вида
          par.scale_ = 2 ' Масштаб
          par.xBase = 30 ' Координаты базовой точки в системе координат вида
          par.yBase = 40

          p = frg.ksInsertFragment(pDefFrg, False, par) ' Вставить ссылку на фрагмент

          doc.ksLightObj(p, 1) ' Подсветить фрагмент
          Kompas.ksMessage("вставка внешнего фрагмента")
          doc.ksLightObj(p, 0) ' Снять выделение фрагмента

          'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          par = Nothing
        End If
      End If

      'UPGRADE_NOTE: Object frg may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      frg = Nothing
    End If
  End Sub

  ' Вставка локального фрагмента

  Sub DrawInsFragment2(ByRef doc As Kompas6API5.Document2D)
    ' определим фрагмент для вставки
    Dim frg As Kompas6API5.Fragment ' Интерфейс ksFragment
    frg = doc.GetFragment ' Интерфейс фрагмента

    Dim pDefFrg As Integer
    Dim par As Kompas6API5.PlacementParam
    Dim p As Integer ' Интерфейс ksPlacementParam
    If Not frg Is Nothing Then ' Интерфейс получен

      ' Определим локальный фрагмент
      If Not frg.ksLocalFragmentDefinition("local") = 0 Then ' Начать определение локального фрагмента

        doc.ksLineSeg(0, 0, 10, 0, 1) ' Объекты локального фрагмента
        doc.ksLineSeg(0, 0, 0, 10, 1)
        doc.ksArcByPoint(0, 0, 10, 10, 0, 0, 10, -1, 1)

        ' Закончить определение локального фрагмента
        pDefFrg = frg.ksCloseLocalFragmentDefinition ' Функция возвращает указатель на определение фрагмента

        If Not pDefFrg = 0 Then ' определение локального фрагмента

          par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PlacementParam) ' Параметры привязки

          If Not par Is Nothing Then ' Интерфейс создан
            par.angle = 45 ' Угол поворота в системе координат вида
            par.scale_ = 2 ' Масштаб
            par.xBase = 30 ' Координаты базовой точки в системе координат вида
            par.yBase = 40

            p = frg.ksInsertFragment(pDefFrg, False, par) ' Вставить ссылку на фрагмент

            doc.ksLightObj(p, 1) ' Подсветить фрагмент
            Kompas.ksMessage("вставка локального фрагмента")
            doc.ksLightObj(p, 0) ' Снять выделение фрагмента

            'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            par = Nothing
          End If
        End If
      End If

      'UPGRADE_NOTE: Object frg may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      frg = Nothing
    End If
  End Sub

  ' Шероховатость

  Sub DrawSpecRough(ByRef doc As Kompas6API5.Document2D)
    Dim par As Kompas6API5.SpecRoughParam ' Интерфейс ksSpecRoughParam
    ' Интерфейс параметров знака неуказанной шероховатости
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_SpecRoughParam)

    If Not par Is Nothing Then ' Интерфейс создан
      par.Init() ' Инициализация

      par.t = 1 ' Наличие знака в скобках ( 1 - есть, 0 - нет )
      par.s = "Rz40" ' Строка текста
      par.sign = 2 ' Тип знака ( 0 - вид обработки не устанавливается, 1 - обработка удалением
      ' слоя материала, 2 - обработка без удаления слоя материала
      par.style = 1 ' Номер стиля текста (1 - обычный текст)

      doc.ksSpecRough(par) ' Задать шероховатость неуказанных поверхностей

      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' Определить имя библиотеки

  Public Function GetLibraryName() As String
    GetLibraryName = "объекты-a" ' Имя библиотеки
  End Function

  ' Головная функция библиотеки - вызывается при выборе пункта меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Kompas6API5.Application)
    Kompas = kompas_ ' Интерфейс приложения КОМПАС
    Dim doc As Kompas6API5.Document2D ' Интерфейс ksDocument2D

    doc = Kompas.ActiveDocument2D ' Получить интерфейс текущего 2D документа

    Select Case command_Renamed
      Case 1
        WorkContour(doc) ' Контур
      Case 2
        TDemWork(doc) ' Технические требования
      Case 3
        DrawViewPointer(doc) ' Стрелка вида
      Case 4
        WorkStamp(doc) ' Работа со штампом
      Case 5
        TableWork(doc) ' Таблица
      Case 6
        DrawEquidistant(doc) ' Эквидистанта
      Case 7
        DrawEllipse(doc) ' Эллипс
      Case 8
        DrawPolyline(doc) ' Полилиния
      Case 9
        DrawNurbs(doc) ' Nurbs
      Case 10
        WorkTolerance(doc) ' Допуск формы
      Case 11
        DrawSpecRough(doc) ' Одинаковая шероховатость
      Case 12
        DrawInsFragment1(doc) ' Вставка фрагмента внешней ссылкой
      Case 13
        DrawInsFragment2(doc) ' Вставка локального фрагмента
    End Select
  End Sub

  ' Сформировать меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 3 '"ENDMENU"'
    ExternalMenuItem = ""
    command_Renamed = -1

    Select Case number
      Case 1 ' Команда 1 - Контур
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Контур"
        command_Renamed = 1
      Case 2 ' Команда 2 - Технические требования
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Технические требования"
        command_Renamed = 2
      Case 3 ' Команда 3 - Стрелка вида
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Стрелка вида"
        command_Renamed = 3
      Case 4 ' Команда 4 - Работа со штампом
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Заполнить штамп"
        command_Renamed = 4
      Case 5 ' Команда 5 - Таблица
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Таблица"
        command_Renamed = 5
      Case 6 ' Команда 6 - Эквидистанта
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Эквидистанта"
        command_Renamed = 6
      Case 7 ' Команда 7 - Эллипс
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Эллипс"
        command_Renamed = 7
      Case 8 ' Команда 8 - Полилиния
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Полилиния"
        command_Renamed = 8
      Case 9 ' Команда 9 - Nurbs
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Nurbs"
        command_Renamed = 9
      Case 10 ' Команда 10 - Допуск формы
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Допуск формы"
        command_Renamed = 10
      Case 11 ' Команда 11 - Одинаковая шероховатость
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Неуказанная шероховатость"
        command_Renamed = 11
      Case 12 ' Команда 12 - Вставка фрагмента внешней ссылкой
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Вставка фрагмента внешней ссылкой"
        command_Renamed = 12
      Case 13 ' Команда 13 - Вставка локального фрагмента
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Вставка локального фрагмента"
        command_Renamed = 13
      Case 14 ' Завершение формирования меню
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