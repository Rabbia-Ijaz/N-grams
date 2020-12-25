#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

char* Array;
int size;
int p; //where the last element is
template<class T>
class String
{
private:
	T* tempArray;
	int stringSize;
	int track;
public:
	String()
	{
		track=-1;
		stringSize=0;
	//	tempArray= new T[stringSize];
	}
	string* getTempArray()
	{
		return tempArray;
	}
	int getStringSize()
	{
		return stringSize;
	}
	int getTrack()
	{
		return track;
	}
	void setStringSize(int s)
	{
		stringSize=s;
	}
	void setTrack(int t)
	{
		track=t;
	}
	int generateStringSize( char* Arr) //generate size of string
	{
		int spaceCount=0;
		int dotCount=0;
		p=strlen(Arr)-1;
		/*////cout<<"***************p*****************"<<p<<'\n';
		////cout<<"***************strlen***********"<<strlen(Arr)-1<<'\n';*/
		
		for(int i=0;i<=p;++i)
		{
			if(Arr[i]==' ')
			{
				spaceCount++;
			}
		}
		for (int i=0;i<=p;++i)
		{
			if(Arr[i]=='.')
			{
				dotCount++;
			}
		}
		int extra;
		if(Arr[p]!='.')
		{
			extra=(dotCount)/2;
		}
		else
		{
			extra=(dotCount-2)/2;
		}
		stringSize=spaceCount+dotCount+extra;
		return stringSize;
	}
	T* generateString(char* Arr) //temporary function
	{
		tempArray= new string[stringSize];
		for(int i=0,j=0;i<stringSize ;)
		{
			string temp="";
			if(Arr[j]=='.')
			{ 
				if(Arr[j-1]=='.')
					j=j-1;
				while(Arr[j]=='.')
				{
					string s=".";
					tempArray[i]=s;
					j++;
					i++;
				}
				j=j-1;;
			}
			else
			{
				while( Arr[j]!='.' && Arr[j]!=' ' && Arr[j]!='\0')
				{
					temp=temp+Arr[j];
					j++;
				}
			}
			
			if(temp!="")
			{
				tempArray[i]=temp;
				++i;
			}
			++j;
			
		}
		return tempArray;
	}
	
};
template< class T>
class Ngram
{
private:
	T* bGram;
	int* bCount;
	int bTrack;
	T* tGram;
	int* tCount;
	int tTrack;
public:
	Ngram()
	{
		bTrack=0;
		tTrack=0;
		bGram=new T[bTrack];
		bCount=new int [bTrack];
		tGram=new T[tTrack];
		tCount=new int[tTrack];
	}
	T* getBgram()
	{
		return bGram;
	}
	int getBtrack()
	{ 
		return bTrack;
	}
	int* getBcount()
	{ 
		return bCount;
	}
	T* getTgram()
	{ 
		return tGram;
	}
	int getTtrack()
	{ 
		return tTrack;
	}
	int* getTcount()
	{ 
		return tCount;
	}



	void setBgram(T* b)
	{
		bGram=b;
	}
	void setBtrack(int bT)
	{ 
		bTrack=bT;
	}
	void setBcount(int* bC)
	{ 
		bCount=bC;
	}
    void setTgram(T* t)
	{
		tGram=t;
	}
	void setTtrack(int tT)
	{ 
		tTrack=tT;
	}
	void setTcount(int* tC)
	{ 
		tCount=tC;
	}
};
Ngram<string>Gram;
String<string>TempStr;

void readInput(const char* Path) //This will read file and save it in char array
{
	string words;
	ifstream infile;
	infile.open( Path);

	if(!infile)
	{
		cout<<"can't open";
		exit(-1);
	}
	int i=0;
	while(infile.good())
	{
		getline(infile,words,'\t');
		//cout<<words;
	}
	//cout<< words<<'\n'<<'\n';
	//cout<<'\n';
	delete[] Array;
	size=words.length();
	//cout<<"************"<<size<<'\n';
	Array=new char[size+1];
	for(int i=0;i<size;++i)
	{
		Array[i]=words[i];
		//cout<<Array[i];
	}
	Array[size]='\0';
	p=size-1; //pointer
//	cout<<'\n';
		
	/*int count=0;
	for(int i=0;i<size;++i)
	{
		cout<<Array[i];
		count++;
	}*/
	/*cout<<'\n';
	cout<<"end character "<<Array[p]<<'\n';
	cout<< "************LENGTH***********"<<size<<'\n'<<'\n';
	cout<< "************POINTER***********"<<p<<'\n'<<'\n';
	cout<<'\n'<<'\n';*/
	infile.close();
}

void removePunctucationMarks()
{
	char* NewArray= new char[size];
	int j=0; //acting as a pointer
	for(int i=0;i<size; ) //(~!@#$%^&*()_+=-`{}[]":;'?><,./ and '\n' )
	{
		if(Array[i]=='~' || Array[i]=='!' || Array[i]=='@'|| Array[i]=='#'|| 
			Array[i]=='$'|| Array[i]=='%'|| Array[i]=='^'|| Array[i]=='&'|| Array[i]=='*'
			|| Array[i]=='('|| Array[i]==')'|| Array[i]=='_'|| Array[i]=='-'|| Array[i]=='+'
			|| Array[i]=='='|| Array[i]=='"'|| Array[i]==';'|| Array[i]==':'|| Array[i]=='/'
			|| Array[i]=='?'|| Array[i]=='>'|| Array[i]==','|| Array[i]=='<' || Array[i] == '`' || Array[i]=='“' ||Array[i]=='”'
			|| Array[i]=='['|| Array[i]==']'|| Array[i]=='{'|| Array[i]=='}'|| Array[i]== '\'' )
		{ 
			++i;
		}
		else if(Array[i]=='\n')
		{
			NewArray[j]=' ';
			++i;
			++j;

		}
			
		else
		{
		NewArray[j]=Array[i];
		j++;
		i++;
		}

	}
	NewArray[j]='\0';
	delete[] Array;
	Array=new char[size];
	Array=NewArray;
	/*int i=0;
	for(;Array[i]!='\0';++i)
	{
		cout<<Array[i];
	}*/
	p=j-1;
	/*cout<<'\n';
    cout<<"end character "<<Array[p]<<'\n';
	cout<< "************ PUNCTUATION LENGTH***********"<<size<<'\n'<<'\n';
	cout<< "************POINTER***********"<<p<<'\n'<<'\n';*/
}


void removeSpacing() //removing any space after dot 
{
	char* NewArray= new char[size];
	int j=0;
	for(int i=0;i<=p;++i)
	{
		if(Array[i]=='.')
		{
			NewArray[j]=Array[i];
			i++;
			j++;
			while(Array[i] ==' ')
			{
				i++;
			}
		}
		else if(Array[i]==' ' && Array[i+1]==' ') //removing extra spaces
		{
			NewArray[j]=Array[i];
			++i;
			while(Array[i]==' ')
			{
				++i;
			}
			++j;
		}
		 
		NewArray[j]=Array[i];
		j++;
	}
	NewArray[j]='\0';
	delete[] Array;
	Array=new char[size];
	Array=NewArray;
	int i=0;
	for(;Array[i]!='\0';++i)
	{
	//	cout<<Array[i];
	}
	p=i-1;
	/*cout<<'\n';
    cout<<"end character "<<Array[p]<<'\n';
	cout<< "************REMOVE SPACING LENGTH***********"<<size<<'\n'<<'\n';
	cout<< "************POINTER***********"<<p<<'\n'<<'\n';*/

}
void insertDots()
{
	char* NewArray= new char[size+5];
	NewArray[0]='.';
	NewArray[1]='.';
	int j=2;
	for(int i=0;i<=p; )
	{
		if(Array[i]=='.')
		{
			NewArray[j]=Array[i];
			j++;
			NewArray[j]='.';
			j++;
			i++;
		}
		else
		{
			NewArray[j]=Array[i];
			j++;
			i++;
		}	
	}
	size=size+5;
	p=j-1;
	if(NewArray[p]!='.')
	{
		NewArray[p+1]='.';
		NewArray[p+2]='.';
		NewArray[p+3]='\0';
		p=p+2;
	}
	else
	{
		NewArray[j]='\0';
	}
	delete[] Array;
	Array= new char[size];
	Array=NewArray;

	/*int i=0;
	for( ;Array[i]!='\0';++i)
	{
		cout<<Array[i];
	}*/
	/*cout<<'\n';
    cout<<"end character "<<Array[p]<<'\n';
	cout<< "************INSERT DOT LENGTH***********"<<size<<'\n'<<'\n';
	cout<< "************POINTER***********"<<p<<'\n'<<'\n';*/

}
char * getText()
{
	return Array;
}


	
void generateUnigrams() //This function will generate unigrams and save them in text file. Name of text will be
							//“unigram.txt”. Path of file will be same as the Project path
{
	
	string *tempArray= new string[TempStr.generateStringSize(Array)];
	tempArray=TempStr.generateString(Array);
	//cout<<"LAST ELEMENT AT INDEX"<<tempArray[TempStr.getStringSize()-1]<<" "<<TempStr.getStringSize()-1<<'\n';

	int track=0;
	string *Unigram=new string[TempStr.getStringSize()];
	int *Count=new int[TempStr.getStringSize()];
	Unigram[0]=".";
	Count[0]=0;
	//cout<<"UNIGRAM "<< Unigram[0]<<'\n'<<'\n';
	for(int i=0;i<TempStr.getStringSize();++i)
	{
		bool ifThere=false;
		string temp=tempArray[i];
		for(int j=0;j<=track;++j)
		{
			if(temp==Unigram[j])
			{
				ifThere=true;
				Count[j]=Count[j]+1;
				break;
			}

		}
		if(ifThere==false)
		{
			track++;
			Unigram[track]=temp;
			Count[track]=1;
		}
	}
	ofstream Myfile;
	Myfile.open("unigram.txt");
	if(Myfile.good())
	{
		for(int i=0;i<=track;++i)
		{
			Myfile<<Unigram[i]<<" "<<Count[i]<<'\n';
		}
	}
	Myfile.close();
	cout<<"***UNIGRAMS***"<<'\n';
	
}

void generateBigrams() //This function will generate bigrams and save them in text file (“bigram.txt”) 
{    
	string *tempArray= new string[TempStr.getStringSize()];
	tempArray=TempStr.getTempArray();
	int track=-1;
	string* Bigram= new string [TempStr.getStringSize()];
	int* Count= new int[TempStr.getStringSize()];
	for(int i=0;i<TempStr.getStringSize()-1;++i)
	{
		string temp="";
		bool ifThere=false;
     	temp=tempArray[i];
		temp+=" ";
		temp+=tempArray[i+1];
		for(int j=0;j<=track;++j)
		{
			if(temp==Bigram[j])
			{
				ifThere=true;
				Count[j]=Count[j]+1;
				break;
			}
		}
		if(ifThere==false)
		{
			track++;
			Bigram[track]=temp;
			Count[track]=1;
		}
	}
	Gram.setBgram(Bigram);
	Gram.setBcount(Count);
	Gram.setBtrack(track);
	ofstream Myfile;
	Myfile.open("bigram.txt");
	if(Myfile.good())
	{
		for(int i=0;i<=track;++i)
		{
			Myfile<<Bigram[i]<<" "<<Count[i]<<'\n';
		}
	}
	Myfile.close();
	cout<<"***BIGRAMS***"<<'\n';

}

void generateTrigrams()//This function will generate bigrams and save them in text file (“trigram.txt”) 
{
	string *tempArray= new string[TempStr.getStringSize()];
	tempArray=TempStr.getTempArray();
	int track=-1;
	string* Trigram= new string [TempStr.getStringSize()];
	int* Count= new int[TempStr.getStringSize()];
	for(int i=0;i<TempStr.getStringSize()-2;++i)
	{
		string temp="";
		bool ifThere=false;
		temp=tempArray[i];
		temp+=" ";
		temp+=tempArray[i+1];
		temp+=" ";
		temp+=tempArray[i+2];
		for(int j=0;j<=track;++j)
		{
			if(temp==Trigram[j])
			{
				ifThere=true;
				Count[j]++;
				break;
			}
		}
		if(ifThere==false)
		{
			track++;
			Trigram[track]=temp;
			Count[track]=1;
		}
	}
	Gram.setTgram(Trigram);
	Gram.setTcount(Count);
	Gram.setTtrack(track);
	ofstream Myfile;
	Myfile.open("trigram.txt");
	if(Myfile.good())
	{
		for(int i=0;i<=track;++i)
		{
			Myfile<<Trigram[i]<<" "<<Count[i]<<'\n';
		}
	}
	Myfile.close();
	cout<<"***TRIGRAMS***"<<'\n';
}

double validateSentance(string str) //This function will validates the given sentence as specified in Step 4a. 
{
	/*cout<<"SIZE STRING "<<str.length()<<'\n';
	cout<<"STRING"<<str<<'\n';*/
	char* Sentence;
	if(str[str.length()-1]!='.')
	{
		Sentence= new char[str.length()+4];
		int sentSize=str.length()+4;
		Sentence[0]='.';
		Sentence[1]='.';
		int k=2;
		for(int j=0;j <str.length();++k,j++)
		{
			Sentence[k]=str[j];
			//cout<<Sentence[i];
		}
		Sentence[str.length()+2 ]='.';
		Sentence[str.length()+3]='.';
		Sentence[str.length()+4]='\0';
		/*for(int i=0;i<=str.length()+3;++i)
		{
			cout<<Sentence[i];
		}*/
	}
	else
	{
		Sentence= new char[str.length()+3];
		int sentSize=str.length()+3;
		Sentence[0]='.';
		Sentence[1]='.';
		int k=2;
		for(int j=0;j <str.length();++k,j++)
		{
			Sentence[k]=str[j];
			//cout<<Sentence[i];
		}
		Sentence[str.length()+2 ]='.';
		Sentence[str.length()+3]='\0';
		/*for(int i=0;i<=str.length()+2;++i)
		{
			cout<<Sentence[i];
		}*/
	}
	
	string* sentString= new string[TempStr.generateStringSize(Sentence)];
	sentString=TempStr.generateString(Sentence);
	/*cout<<"WHAT"<<"   "<< TempStr.getTrack()<< '\n';
	for(int i=0;i<TempStr.getStringSize();++i)
	{ 
		cout<<sentString[i]<<" ";
	}*/


	string *btempArray= new string[TempStr.getStringSize()];
	btempArray=TempStr.getTempArray();
	int btrack=-1;
	string* Bigram= new string [TempStr.getStringSize()];
	int* bCount= new int[TempStr.getStringSize()];
	for(int i=0;i<TempStr.getStringSize()-1;++i)
	{
		string temp="";
		bool ifThere=false;
		temp=btempArray[i];
		temp+=" ";
		temp+=btempArray[i+1];
		for(int j=0;j<=btrack;++j)
		{
			if(temp==Bigram[j])
			{
				ifThere=true;
				bCount[j]=bCount[j]+1;
				break;
			}
		}
		if(ifThere==false)
		{
			btrack++;
			Bigram[btrack]=temp;
			bCount[btrack]=1;
		}
	}
	/*cout<<"****UNIGRAM SENTENCE****"<<'\n';
	for(int i=0;i<=btrack;++i)
	{
		cout<<Bigram[i]<<" "<<bCount[i]<<'\n';
	}
*/

	string *ttempArray= new string[TempStr.getStringSize()];
	ttempArray=TempStr.getTempArray();
	int ttrack=-1;
	string* Trigram= new string [TempStr.getStringSize()];
	int* tCount= new int[TempStr.getStringSize()];
	for(int i=0;i<TempStr.getStringSize()-2;++i)
	{
		string temp="";
		bool ifThere=false;
		temp=ttempArray[i];
		temp+=" ";
		temp+=ttempArray[i+1];
		temp+=" ";
		temp+=ttempArray[i+2];
		for(int j=0;j<=ttrack;++j)
		{
			if(temp==Trigram[j])
			{
				ifThere=true;
				tCount[j]=tCount[j]+1;
				break;
			}
		}
		if(ifThere==false)
		{
			ttrack++;
			Trigram[ttrack]=temp;
			tCount[ttrack]=1;
		}
	}

	//cout<<"****TRIGRAM SENTENCE****"<<'\n';
	//for(int i=0;i<=ttrack;++i)
	//{
	//	cout<<Trigram[i]<<" "<<tCount[i]<<'\n';
	//}

    double Valid=0.0;
	for(int i=0; i<=btrack && i<=ttrack ;++i)
	{
		int freq_a, freq_b;
		bool found = false;
		for(int j=0 ;j<=Gram.getTtrack();++j)
		{
			if(Trigram[i]==Gram.getTgram()[j])
			{
				found = true;
				freq_a=Gram.getTcount()[j];
				break;
			}

		}
		if (!found)
		{	
			return 1;
		}
		found = false;
		for(int j=0 ;j<=Gram.getBtrack();++j)
		{
			if(Bigram[i]==Gram.getBgram()[j])
			{
				found = true;
				freq_b=Gram.getBcount()[j];
				break;
			}

		}
		if(!found)
		{
			return 1;
		}

		Valid= Valid + log((double)freq_a/(double)freq_b);

	}
	return Valid;

}

string sentenceCreation(int position)//This function will generate the sentence as specified in Step 4b.
	                                 //For example:  Suppose if we want to choose “. I do” as first trigram 
									//then we will pass integer 11 to the above given function.
{
	string S="";
	string T=Gram.getTgram()[position-1];
	//cout<<"TRIGRAM "<<T<<endl;
	string Tri="";
	
	bool Break=false;
	int Next=-1;
	bool c=false;
	while(Break==false)
	{   
		
		string Tri="";
		int cB=0,cT=0; 
		double P;
		double Max=-10000000;

		for(int i=0;i<T.length();++i)  //removes first word and put it in Tri string
		{

			while(c==false)
			{
				if(T[i]!=' ')
				{
					i++;
				}
				else if(T[i]==' ')
				{ 
					c=true;
					i++;
				}
			}
			if(c==true)
			{
				Tri+=T[i];
			}
			
		}
		c=false;
	//	cout<<"TRI "<<Tri<<endl;
		
		for(int i=0; i<=Gram.getBtrack();++i)
		{
			if(Tri==Gram.getBgram()[i])
			{
				cB=Gram.getBcount()[i];
				break;
			}
		}
		//cout<<"CB "<<cB<<endl;
	    bool found=false;
		for(int t=0; t<=Gram.getTtrack(); ++t)
		{
			if( Gram.getTgram()[t].find(Tri)==0)
			{
				cT=Gram.getTcount()[t];
				found=true;
				//cout<<"CT "<<cT<<endl;
			}
			
			if(found==true)
			{
				P= log((double)cT/(double)cB);
				if(P>Max)
				{
					Max=P;
					//cout<<"****MAX P*** "<<Max<<endl; 
					Next=t;
					//cout<<"******* T **** "<<Next<<endl;;
					
				}
			}
		

		}
		T=Gram.getTgram()[Next];
	//	cout<<"NEW T  "<<T<<endl;
		//b++;
		S+=' ';
		S+=T;
		if(T[T.length()-1]=='.')
		{
			Break=true;
		}
		
		
	}
	//cout<<"***SENTENCE "<<S<<endl;
	char* Final=new char[S.length()];
	for(int i=0;i<S.length();++i)
	{
		Final[i]=S[i];
	}
	string* a=new string[TempStr.generateStringSize(Final)];
	a=TempStr.generateString(Final);
	//cout<<"****FINAL SIZE **** "<<TempStr.getStringSize()<<endl;
	string F="";
	F+=a[0];
	//F+=' ';
	//F+=a[1];
	//cout<<"FF "<<F<<endl;
	int i=1;
	int co=3;
	for(;a[i]!=".";++i)
	{
		if(co==3)
		{
			F+=' ';
		F+=a[i];
		
		co=0;
		}
		++co;
		
	}
	F+=a[i];
	//F+='\0';
	cout<<"FINAL"<<F;
	return F;
     

}									

