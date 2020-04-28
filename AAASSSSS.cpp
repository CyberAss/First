/* [N - 10]
    Тарабурин Александр
    Получение первой цифры от деления *this на n*10^k
*/

uint64_t Natural::DIV_NN_Dk(const Natural& n, const uint64_t& k) {
    Natural temp(n); //Временный натурал для поиска значения
    temp.MUL_Nk_N(k);
    if (COMM_NN_D(temp) == 1) return 0; // Если второе число больше первого цифра равна 0
    Natural mem(temp); //Натурал хранящий n*10^k
    for (int i = 2; i <= 10; i++) {
        if (COMM_NN_D(temp.MUL_ND_N(i)) == 1) return i - 1; //Если натурал умноженный на цифру больше,
        //то вернется предыдущее значение
        temp = mem;
    }//Если после этого прохода не нашлась цифра, надо еще раз умножить на 10^k,
    //так чтобы степень второго была на 1 меньше, чем у первого
    temp.MUL_Nk_N(getRawDeg() - temp.getRawDeg() - 1);
    mem = temp;
    for (int i = 2; i <= 10; i++) {
        if (COMM_NN_D(temp.MUL_ND_N(i)) == 1) return i - 1;
        temp = mem;
    }
    //После этого прохода сделаем степени двух натуралов одинаковыми
    temp.MUL_Nk_N(1);
    mem = temp;
    for (int i = 2; i < 10; i++) {
        if (COMM_NN_D(temp.MUL_ND_N(i)) == 1) return i - 1;
        temp = mem;
    }
    return 9;
}

/*  [N - 11]
    Тарабурин Александр
    Краткое описание модуля...
    Ссылки на документацию, использованную при разработке.
*/

Natural& Natural::DIV_NN_N(const Natural& n) {
    Natural first(*this), res("0"), znach("1");
    uint64_t numb, step;

    if (n == Natural{ "1" })
        return *this;

    while (first.COMM_NN_D(n) != 1) { //Исполняется пока this >= n
        numb = Natural(first).DIV_NN_Dk(n, 0); //Находиться первая цифра от деления this на n
        znach = Natural(n).MUL_ND_N(numb); //Значение для поиска положения текущей цифры
        step = 0;//Обнуляем значение степени, в которое будем помещать текущую цифру
        while (first.COMM_NN_D(znach.MUL_Nk_N(1)) == 2) step++; // Ищем эту степень сравнивая c*n*10^step c *this
        res.ADD_NN_N(Natural("1").MUL_Nk_N(step).MUL_ND_N(numb)); //Добавим полученное значение к резульатату
        Natural a(Natural("1").MUL_Nk_N(step).MUL_NN_N(n));
        first.SUB_NDN_N(a, numb);// Вычтем из *this полученное значение
        first.NZER_N_B();//Уберем лишние нули
    }
    *this = res;
    return *this;
}