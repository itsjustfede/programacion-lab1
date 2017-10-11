/** \brief recibe dos valores flotantes, los suma y retorna su resultado
 *
 * \param primer operando
 * \param segundo operando
 * \return resultado
 *
 */


float FuncionSumar (float n1, float n2)
{
    float resultado;
    resultado=n1+n2;
    return resultado;
}

/** \brief recibe dos valores flotantes, los resta y retorna su resultado
 *
 * \param primer operando
 * \param segundo operando
 * \return resultado
 *
 */

float FuncionRestar (float n1, float n2)
{
    float resultado;
    resultado=n1-n2;
    return resultado;

}

/** \brief recibe dos valores flotantes, los divide y retorna su resultado
 *
 * \param primer operando
 * \param segundo operando
 * \return resultado
 *
 */

float FuncionDividir (float n1, float n2)
{
    float resultado;
    resultado=n1/n2;
    return resultado;
}

/** \brief recibe dos valores flotantes, los multiplica y retorna su resultado
 *
 * \param primer operando
 * \param segundo operando
 * \return resultado
 *
 */

float FuncionMultiplicar (float n1, float n2)
{
    float resultado;
    resultado=n1*n2;
    return resultado;
}

/** \brief recibe un valor, realiza el factorial del mismo y retorna el resultado
 *
 * \param primer operando
 * \return resultado
 *
 */

int FuncionFactorial (float n1)
{
    int i,resultado=1;
    for (i=n1;i>1;i--)
        {
        resultado*=i;
        }
    return resultado;

}

