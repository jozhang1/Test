public class Book{
	private String name;
	private Test[] author;
	private int qtyInStock;
	public Book(){
		this.name="test";
		this.author = new test();
		this.qtyInStock  = 1;
	}
	public Book(String name, Test[] author, int qtyInstock){
		this.name=name;
		this.author = author;
		this.qtyInStock  = qtyInstock;
	}
	public String getAuthor(){
		String s = new String();
		for(int i = 0;i<author.length;i++)
			s+=( (author[i]).getName());
		return s;
	}
	public void setName(String name){
		this.name=name;
	}
	@Override
	public boolean equals(Object book){
		
		if(book==null)return false;
		if(this==book)return true;
		Book b = (Book)book;
		if(b.author==author && b.name==name && b.qtyInStock==qtyInStock)
			return true;
		return false;
	}
}