#include "head.h"

string formulaToPostfix(string str, bool brackets, bool func)
{
	char temp;
	if (brackets)
	{
		for (usi i = 1; i < str.size() - 1; i++)
		{
			if (str[i] == 42 || str[i] == 47)
			{
				if (str[i + 1] != 40 && str[i - 1] != 41)
				{
					string strTemp;
					string strTemp2;
					for (usi j = 0; j < i - 1; j++)
						strTemp.push_back(str[j]);
					for (usi j = i - 1; j < str.size(); j++)
						strTemp2.push_back(str[j]);
					str = strTemp + "(" + strTemp2;
					strTemp.clear();
					strTemp2.clear();
					for (usi j = 0; j <= i + 2; j++)
						strTemp.push_back(str[j]);
					for (usi j = i + 3; j < str.size(); j++)
						strTemp2.push_back(str[j]);
					str = strTemp + ")" + strTemp2;
					i = strTemp.size();
				}
				else
				{
					if (str[i - 1] == 41 && str[i + 1] == 40)
					{
						usi bracket2Index;
						usi tempIndex = 0;
						usi tempIndex2 = 0;
						for (usi j = i - 2; j >= 0; j--)
						{
							if (str[j] == 41)
								tempIndex++;
							else if (str[j] == 40)
							{
								if (tempIndex == tempIndex2)
								{
									bracket2Index = j;
									break;
								}
								else
									tempIndex2++;
							}
						}
						string strTemp;
						string strTemp2;
						for (usi j = 0; j < bracket2Index; j++)
							strTemp.push_back(str[j]);
						for (usi j = bracket2Index; j < str.size(); j++)
							strTemp2.push_back(str[j]);
						str = strTemp + "(" + strTemp2;
						i++;
						string strTemp3;
						for (usi j = strTemp.size() + 2; j < i - 1; j++)
							strTemp3.push_back(str[j]);
						usi tempIndex3 = strTemp3.size();
						strTemp3 = formulaToPostfix(strTemp3, 1, 0);
						tempIndex3 = strTemp3.size() - tempIndex3;
						string strTemp6, strTemp7;
						for (usi j = 0; j < strTemp.size() + 2; j++)
							strTemp6.push_back(str[j]);
						for (usi j = strTemp.size() + 2 + strTemp3.size(); j < str.size(); j++)
							strTemp7.push_back(str[j]);
						str = strTemp6 + strTemp3 + strTemp7;
						i = i + tempIndex3;
						tempIndex = 0;
						tempIndex2 = 0;
						for (usi j = i + 2; j < str.size(); j++)
						{
							if (str[j] == 40)
								tempIndex++;
							else if (str[j] == 41)
							{
								if (tempIndex == tempIndex2)
								{
									bracket2Index = j;
									break;
								}
								else
									tempIndex2++;
							}
						}
						strTemp.clear();
						strTemp2.clear();
						for (usi j = 0; j <= bracket2Index; j++)
							strTemp.push_back(str[j]);
						for (usi j = bracket2Index + 1; j < str.size(); j++)
							strTemp2.push_back(str[j]);
						str = strTemp + ")" + strTemp2;
						strTemp3.clear();
						for (usi j = i + 2; j < bracket2Index; j++)
							strTemp3.push_back(str[j]);
						tempIndex3 = strTemp3.size();
						strTemp3 = formulaToPostfix(strTemp3, 1, 0);
						tempIndex3 = strTemp3.size() - tempIndex3;
						strTemp6.clear();
						strTemp7.clear();
						for (usi j = 0; j <= i + 1; j++)
							strTemp6.push_back(str[j]);
						for (usi j = bracket2Index; j < str.size(); j++)
							strTemp7.push_back(str[j]);
						str = strTemp6 + strTemp3 + strTemp7;
						i = strTemp.size() + tempIndex3;
					}
					else
					{
						if (str[i - 1] == 41)
						{
							usi bracket2Index;
							usi tempIndex = 0;
							usi tempIndex2 = 0;
							for (usi j = i - 2; j >= 0; j--)
							{
								if (str[j] == 41)
									tempIndex++;
								else if (str[j] == 40)
								{
									if (tempIndex == tempIndex2)
									{
										bracket2Index = j;
										break;
									}
									else
										tempIndex2++;
								}
							}
							string strTemp;
							string strTemp2;
							for (usi j = 0; j < bracket2Index; j++)
								strTemp.push_back(str[j]);
							for (usi j = bracket2Index; j < str.size(); j++)
								strTemp2.push_back(str[j]);
							str = strTemp + "(" + strTemp2;
							i++;
							string strTemp3;
							for (usi j = strTemp.size() + 2; j < i - 1; j++)
								strTemp3.push_back(str[j]);
							usi tempIndex3 = strTemp3.size();
							strTemp3 = formulaToPostfix(strTemp3, 1, 0);
							tempIndex3 = strTemp3.size() - tempIndex3;
							string strTemp6, strTemp7;
							for (usi j = 0; j < strTemp.size() + 2; j++)
								strTemp6.push_back(str[j]);
							for (usi j = strTemp6.size() + strTemp3.size() - tempIndex3; j < str.size(); j++)
								strTemp7.push_back(str[j]);
							str = strTemp6 + strTemp3 + strTemp7;
							i = i + tempIndex3;
							string strTemp4;
							for (usi j = 0; j <= i + 1; j++)
								strTemp4.push_back(str[j]);
							string strTemp5;
							for (usi j = i + 2; j < str.size(); j++)
								strTemp5.push_back(str[j]);
							str = strTemp4 + ")" + strTemp5;
						}
						else if (str[i + 1] == 40)
						{
							usi bracket2Index;
							usi tempIndex = 0;
							usi tempIndex2 = 0;
							for (usi j = i + 2; j < str.size(); j++)
							{
								if (str[j] == 40)
									tempIndex++;
								else if (str[j] == 41)
								{
									if (tempIndex == tempIndex2)
									{
										bracket2Index = j;
										break;
									}
									else
										tempIndex2++;
								}
							}
							string strTemp;
							string strTemp2;
							for (usi j = 0; j <= bracket2Index; j++)
								strTemp.push_back(str[j]);
							for (usi j = bracket2Index + 1; j < str.size(); j++)
								strTemp2.push_back(str[j]);
							str = strTemp + ")" + strTemp2;
							string strTemp3;
							for (usi j = i + 2; j < bracket2Index; j++)
								strTemp3.push_back(str[j]);
							usi tempIndex3 = strTemp3.size();
							strTemp3 = formulaToPostfix(strTemp3, 1, 0);
							tempIndex3 = strTemp3.size() - tempIndex3;
							string strTemp6, strTemp7;
							for (usi j = 0; j <= i + 1; j++)
								strTemp6.push_back(str[j]);
							for (usi j = bracket2Index; j < str.size(); j++)
								strTemp7.push_back(str[j]);
							str = strTemp6 + strTemp3 + strTemp7;
							i = i + tempIndex3;
							string strTemp4;
							for (usi j = 0; j < i - 1; j++)
								strTemp4.push_back(str[j]);
							string strTemp5;
							for (usi j = i - 1; j < str.size(); j++)
								strTemp5.push_back(str[j]);
							str = strTemp4 + "(" + strTemp5;
							i++;
						}
					}
				}
			}
		}
	}
	if (func)
	{
		for (usi i = 0; i < str.size(); i++)
		{
			if (str[i] == 43 || str[i] == 45 || str[i] == 42 || str[i] == 47)
			{
				temp = str[i];
				if (str[i + 1] == 40)
				{
					usi bracket2Index;
					usi tempIndex = 0;
					usi tempIndex2 = 0;
					for (usi j = i + 2; j < str.size(); j++)
					{
						if (str[j] == 40)
							tempIndex++;
						else if (str[j] == 41)
						{
							if (tempIndex == tempIndex2)
							{
								bracket2Index = j;
								break;
							}
							else
								tempIndex2++;
						}
					}
					string strTemp;
					for (usi j = i + 2; j < bracket2Index; j++)
						strTemp.push_back(str[j]);
					strTemp = formulaToPostfix(strTemp, 0, 1);
					for (usi j = 0; j < strTemp.size(); j++)
						for (usi k = i + 2 + j; k != i + 3 + j ; k++)
							str[k] = strTemp[j];
					string strTemp2;
					usi tempIndex3 = 0;
					for (usi j = bracket2Index + 1; j < str.size(); j++)
					{
						strTemp2.push_back(str[j]);
						tempIndex3++;
					}
					for (usi j = 0; j < tempIndex3; j++)
						str.pop_back();
					str.push_back(temp);
					for (usi j = 0; j < strTemp2.size(); j++)
						str.push_back(strTemp2[j]);
					for (usi j = i; j < str.size() - 1; j++)
						str[j] = str[j+1];
					str.pop_back();
					i = bracket2Index;
				}
				else
				{
					str[i] = str [i + 1];
					str[i + 1] = temp;
					i++;
				}
			}
		}
	}
	return str;
}