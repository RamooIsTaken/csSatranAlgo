#pragma once
#ifndef TASLAR_H
#define TASLAR_H



class Taslar
{
public:
	Taslar(char ch, char rnk, float points);
	float getPuan() const;
	bool getTehtid() const;
	char getChar() const;
	char getRenk() const;
	static int getSayac() ;
	void kontrol(char matris[8][8][3],int x,int y);

protected:
	char karakter;
	char renk;
	float puan;
	bool tehtid;
	

private:
	static int sayac;
	
};


#endif 


