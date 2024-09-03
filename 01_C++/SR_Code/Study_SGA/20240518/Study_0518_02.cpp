#include <iostream>
#include <string>
using namespace std;

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式063 僥濠翮擊 薑熱煎 滲��(stoi) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
/*
int main() {

	string str1 = "10";
	string str2 = "2.456";
	string str3 = "456 僥濠翮";
	
	int num1 = stoi(str1);
	int num2 = stoi(str2);
	int num3 = stoi(str3);


	// str1曖 僥濠翮煎 薑熱煎 滲�納狤� 10
	// str2曖 僥濠翮擊 薑熱煎 滲�納狤� 模熱薄 幗葡 2
	// str3曖 僥濠翮擊 薑熱煎 滲�納狤� 456
	cout << num1 << ", " << num2 << ", " << num3 << endl;

	return 0;
}
*/
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式064 僥濠翮擊 璋濠煎 滲��(stringstream) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
/*
#include <sstream>
int main() {
	stringstream ss;

	double number1 = 0.0;

	ss << "1.2,2.6-3.8!4.7=8.9";

	cout << "== string to double ==" << endl;
	while (!ss.eof())
	{
		ss >> number1;
		ss.ignore();
		
		cout << number1 << ", ";
	}

	ss.clear();
	ss.str("");
	ss << "1," << "2" << 3 << " " << 4;

	int number2 = 0;

	cout << endl << "== string to int ==" << endl;
	while (!ss.eof())
	{
		ss >> number2;
		ss.ignore();

		cout << number2 << ", ";
	}


	return 0;
}
*/
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式065 僥濠翮 薑溺ж晦(sort) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// string A = "vialeqwer"; 摹樹и匙縑 sort(A.begin(), A.end()); 虜萇�� A高擊 轎溘 ж賊 vialeqwer 檜匙檜 a,b,c... 牖憮渠煎 薑溺腎橫 轎溘脾

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式067 璋濠蒂 僥濠翮煎 滲�納炱�(to_string) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
/*
int main(){

	int number = 10;
	double number2 = 67.8;

	string a = to_string(number);
	string b = to_string(number2);

	cout << "a曖 高擎 : " << a << endl;
	cout << "b曖 高擎 : " << b << endl;

	return 0;
}
*/

// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式069 ん檣攪 檜пж晦(*) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
/*
int main() {

	int number1 = 10;
	int* pt1 = &number1;

	cout << "number1 : " << number1 << " (size : " << sizeof(number1) << ")" << endl;
	cout << "pointer1 : " << pt1 << " (size : " << sizeof(pt1) << ")" << endl;

	cout << "高擎 : " << *pt1 << endl;

	// int* 濠猿⑽縑 ん檣攪輿模高戲煎 &number1曖 輿模蒂 乾堅螃啊棻朝 匙.. 轎溘й陽 斜寰縑 氬曹 高擊 碳楝螢陽朝 摹樹и pt1擅縑 *蒂 稱橫敷 *pt1煎 碳溥螃賊 斜 輿模寰縑 殖萼 高擊 乾堅螃啪脹棻.
	// &朝 輿模高擊 碳楝螞棻朝 曖嘐

	return 0;
}
*/
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式070 ん檣攪 滲熱 餌辨ж晦(*) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
/*
#include <vector> // 漱攪餌辨

int Pfunc(vector<string> *info) // int⑽ л熱 (л熱寰縑朝 寥攪 蝶お葭擊 檜辨и棻朝 ん檣攪 info)
{
	if (info->empty() == true)    
		return 0;
	else
		return sizeof(info);

}

int main() {

	vector<string> message;
	message.push_back("堅溥 濰捱");
	message.push_back("繫遽唳!");
	message.push_back("瞰耀 檜葷擎");
	message.push_back("...鼠歙橾梱");

	cout << "ん檣攪 檣濠 觼晦 : " << Pfunc(&message) << endl;   
	cout << "錳楚 滲熱 觼晦 : " << sizeof(message) << endl;


	return 0;
}
*/
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式071 ん檣攪 寡翮 餌辨ж晦(*) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式

/*
int main() {

	const int kSize = 3;

	int numbers[kSize] = { 10, 20, 30 };
	int* p1 = numbers;

	int no1 = 1;
	int no2 = 2;
	int no3 = 3;
	int* p2[kSize] = { &no1, &no2, &no3 }; // 寡翮寰縑 檜嘐 0,1,2曖 п渡ж朝 輿模高擊 厥橫菩 鼻鷓

	for (int i = 0; i < kSize; i++)
		cout << "P1[" << i << "] = " << *(p1 + i) << endl;

	for (int i = 0; i < kSize; i++)
		cout << "P2[" << i << "] = " << *p2[i] << endl; // *(p2 + i)煎 轎溘й 唳辦 輿模陛 釭螞棻. 斜 檜嶸朝 p2縑憮 寡翮寰縑 蟾晦�音� 高菟擊 檜嘐 &煎 no1~3高擊 碳楝諮晦 陽僥檜棻. 斜楚憮 斜 寰縑 ル衛脹 高擊 釭顫頂溥賊 143廓曖 摹樹и 高擊 斜渠煎 瞳橫撿 ル衛腎朝匙擊 憲熱 氈棻.


	return 0;
}
*/
// 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式 ん檣攪 寡翮 翱蝗 (*) 式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式

int main() {

	// 寡翮瞪羹曖 輿模蒂 乾擊陽 餌辨ж朝匙檜 惘雛?
	int Num1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* ptNum1 = Num1;

	for (int i = 0; i < 10; i++)
	{
		cout << *(ptNum1+i) << endl;
	}
	

	int child = 3;
	string Y1 = "翱撩煙";
	string Y2 = "翱撩遵";
	string Y3 = "翱撩ж";

	string* pyyy[3] = { &Y1, &Y2, &Y3 };

	cout << "翱嬪瑰 彌�ˉ� 濠喪熱朝 : " << to_string(child) << "貲" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << *pyyy[i] << "殮棲棻." << endl;
		
		cout << " *(pyyy + i)蒂 餌辨й 唳辦 : " << *(pyyy + i) << " &煎 檜嘐 0, 1, 2 高 陝濠 餌辨ц戲嘎煎 檜溢啪 輿模高擊 釭顫鹿棲棻." << endl;
	}


	return 0;
}